// This is a c++ channel implementation for refrence


#ifndef _PROPOSED_CHANNELS_H_
#define _PROPOSED_CHANNELS_H_

#include <mutex>
#include <array>
#include <atomic>
#include <cassert>

{
    public:
        // the number of elements the channel can contain
        int capacity() const = 0;

        // check if the channel is closed
        bool is_closed() const = 0;

        // close the channel
        void close() = 0;

        // insert element
        bool insert(T &) = 0;

        // extract next element
        ??? extract() = 0;
    };

    // templated channel synchronization implementation
    template<typename T, int BUFFER_SIZE>
    class _channel_sync final : public _channel_sync_base<T>
    {
    public:
        constexpr int capacity() const override {
            return BUFFER_SIZE;
        }

        void close() override {
            unique_lock<mutex> lock{ _sync_lock };
            _closed.store(true);
            lock.unlock();
            _sync.notify_all();
        }

        bool is_closed() const override {
            return _closed.load();
        }

        bool insert(T &t) override {
            unique_lock<mutex> lock{ _sync_lock };
            _sync.wait(lock, [this] {return _head != _tail || _closed.load(); });
            if (_head == _tail)
                return false;

            auto head_local = _head.load();
            _buffer[head_local] = move(t);

            if (_tail == -1)
                _tail = head_local;

            _head = (head_local + 1) % _buffer.size();
            lock.unlock();
            _sync.notify_one();
            return true;
        }

        entry extract() override {
            unique_lock<mutex> lock{ _sync_lock };
            _sync.wait(lock, [this] {return _tail != -1 || _closed.load(); });
            if (_tail == -1)
                return{ T{}, false };

            auto tail_local = _tail.load();
            auto t_local = move(_buffer[tail_local]);

            tail_local = (tail_local + 1) % _buffer.size();
            _tail = (tail_local == _head) ? -1 : tail_local;
            lock.unlock();
            _sync.notify_one();

            return{ move(t_local), true };
        }

    private:
        mutex _sync_lock;
        condition_variable _sync;
        atomic<bool> _closed{ false };
        atomic<int> _head{ 0 };
        atomic<int> _tail{ -1 };
        array<T, BUFFER_SIZE> _buffer;
    };

    // specialized channel synchronization implementation for a zero sized buffer
    template<typename T>
    class _channel_sync<T, 0> final : public _channel_sync_base<T>
    {
    public:
        constexpr int capacity() const override {
            return 0;
        }

        bool is_closed() const override {
            return _closed.load();
        }

        void close() override {
            unique_lock<mutex> lock{ _sync_lock };
            _closed.store(true);
            lock.unlock();
            _sync.notify_all();
        }

        bool insert(T &t) override {
            unique_lock<mutex> lock{ _sync_lock };
            _sync.wait(lock, [&] { return _value.load() == nullptr || _closed.load(); });
            if (_value.load() != nullptr)
                return false;

            _value = &t;

            lock.unlock();
            _sync.notify_one();

            lock.lock();
            _sync.wait(lock, [&] { return _value.load() == nullptr; });
            return true;
        }

        entry extract() override {
            unique_lock<mutex> lock{ _sync_lock };
            _sync.wait(lock, [&] { return _value.load() != nullptr || _closed.load(); });
            if (_value.load() == nullptr)
                return{ T{}, false };

            assert(_value.load() != nullptr);
            auto value_local = move(*_value);
            _value = nullptr;

            lock.unlock();
            _sync.notify_one();
            return{ move(value_local), true };
        }

    private:
        mutex _sync_lock;
        condition_variable _sync;
        atomic<bool> _closed{ false };
        atomic<T *> _value{ nullptr };
    };

    template<typename T>
    class _channel_iterator
    {
    public:
        using channel_entry = typename _channel_sync_base<T>::entry;

    public:
        _channel_iterator()
            : _current{ T{}, false }
            , _s{ nullptr }
        { /* end iterator */ }

        _channel_iterator(_channel_sync_base<T> *s)
            : _s{ s }
        {
            assert(_s != nullptr);
            _current = _s->extract();
        }

        bool operator==(const _channel_iterator &other) const {
            // Iterators are only equal if both represent a closed channel
            return ((!_current.second) && (!other._current.second));
        }

        bool operator!=(const _channel_iterator &other) const {
            return (!(*this == other));
        }

        T operator*() {
            assert(_s != nullptr);
            return move(_current.first);
        }

        channel_entry *operator->() {
            return &_current;
        }

        _channel_iterator& operator++() {
            assert(_s != nullptr);
            _current = _s->extract();
            return *this;
        }

    private:
        channel_entry _current;
        _channel_sync_base<T> *_s;
    };

    // channel class
    template<typename T>
    class channel
    {
    public:
        using iterator = typename _channel_iterator<T>;
        using channel_entry = typename iterator::channel_entry;

    public:
        channel(const channel &other)
            : _sync{ other._sync }
        { }

        channel(channel &&other)
            : _sync{ move(other._sync) }
        { }

        channel &operator=(const channel &other) {
            _sync = other->_sync;
            return *this;
        }

        channel &operator=(channel &&other) {
            _sync = move(other->_sync);
            return *this;
        }

    protected:
        channel(unique_ptr<_channel_sync_base<T>> sync)
            : _sync{ move(sync) }
        { }

    public:
        int capacity() const {
            return _sync->capacity();
        }

        bool is_closed() const {
            return _sync->is_closed();
        }

        void close() {
            _sync->close();
        }

        bool insert(T &t) {
            return _sync->insert(t);
        }

        channel & operator<<(T t) {
            insert(t);
            return *this;
        }

        channel_entry extract() {
            return _sync->extract();
        }

        channel & operator>>(T &t) {
            bool not_used;
            tie(t, not_used) = extract();
            return *this;
        }

    public:
        iterator begin() {
            return iterator{ _sync.get() };
        }

        iterator end() {
            return iterator{};
        }

    private:
        shared_ptr<_channel_sync_base<T>> _sync;
    };

    // channel with no internal buffer (blocking)
    template <typename T>
    class blocking_channel final : public channel<T>
    {
    public:
        blocking_channel()
            : channel(make_unique<_channel_sync<T, 0>>())
        { }
    };

    // channel with an internal buffer (non-blocking)
    template <typename T, int BUFFER_SIZE>
    class buffered_channel final : public channel<T>
    {
    public:
        buffered_channel()
            : channel(make_unique<_channel_sync<T, BUFFER_SIZE>>())
        { }
    };
}

#endif // _PROPOSED_CHANNELS_H_