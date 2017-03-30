
typedef unsigned long size_t;

typedef signed int wchar_t;

typedef struct  {
  signed int quot;
  signed int rem;
  
} div_t;

typedef struct  {
  signed long quot;
  signed long rem;
  
} ldiv_t;

typedef struct  {
  signed long long quot;
  signed long long rem;
  
} lldiv_t;

extern size_t __ctype_get_mb_cur_max(void) __attribute__((__nothrow__, __leaf__));

extern double atof(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern signed int atoi(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern signed long atol(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern signed long long atoll(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern double strtod(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern float strtof(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long double strtold(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed long strtol(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern unsigned long strtoul(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed long long strtoll(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern unsigned long long strtoull(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int rand(void) __attribute__((__nothrow__, __leaf__));

extern void srand(unsigned int  __seed) __attribute__((__nothrow__, __leaf__));

extern signed int rand_r(unsigned int  * __seed) __attribute__((__nothrow__, __leaf__));

extern void  *malloc(size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));

extern void  *calloc(size_t  __nmemb, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));

extern void  *realloc(void  * __ptr, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__warn_unused_result__));

extern void free(void  * __ptr) __attribute__((__nothrow__, __leaf__));

extern void  *aligned_alloc(size_t  __alignment, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__)) __attribute__((__alloc_size__(2)));

extern void abort(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern signed int atexit(void ( * __func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int at_quick_exit(void ( * __func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void quick_exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void _Exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern char  *getenv(const char  * __name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int system(const char  * __command);

typedef signed int ( *__compar_fn_t)(const void  * , const void  * );

extern void  *bsearch(const void  * __key, const void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar) __attribute__((__nonnull__(1, 2, 5)));

extern void qsort(void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar) __attribute__((__nonnull__(1, 4)));

extern signed int abs(signed int  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern signed long labs(signed long  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern signed long long llabs(signed long long  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern div_t div(signed int  __numer, signed int  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern ldiv_t ldiv(signed long  __numer, signed long  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern lldiv_t lldiv(signed long long  __numer, signed long long  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern signed int mblen(const char  * __s, size_t  __n) __attribute__((__nothrow__, __leaf__));

extern signed int mbtowc(wchar_t  *__restrict  __pwc, const char  *__restrict  __s, size_t  __n) __attribute__((__nothrow__, __leaf__));

extern signed int wctomb(char  * __s, wchar_t  __wchar) __attribute__((__nothrow__, __leaf__));

extern size_t mbstowcs(wchar_t  *__restrict  __pwcs, const char  *__restrict  __s, size_t  __n) __attribute__((__nothrow__, __leaf__));

extern size_t wcstombs(char  *__restrict  __s, const wchar_t  *__restrict  __pwcs, size_t  __n) __attribute__((__nothrow__, __leaf__));

typedef unsigned char __u_char;

typedef unsigned short __u_short;

typedef unsigned int __u_int;

typedef unsigned long __u_long;

typedef char __int8_t;

typedef unsigned char __uint8_t;

typedef signed short __int16_t;

typedef unsigned short __uint16_t;

typedef signed int __int32_t;

typedef unsigned int __uint32_t;

typedef signed long __int64_t;

typedef unsigned long __uint64_t;

typedef signed long __quad_t;

typedef unsigned long __u_quad_t;

typedef unsigned long __dev_t;

typedef unsigned int __uid_t;

typedef unsigned int __gid_t;

typedef unsigned long __ino_t;

typedef unsigned long __ino64_t;

typedef unsigned int __mode_t;

typedef unsigned long __nlink_t;

typedef signed long __off_t;

typedef signed long __off64_t;

typedef signed int __pid_t;

typedef struct  {
  signed int __val[2];
  
} __fsid_t;

typedef signed long __clock_t;

typedef unsigned long __rlim_t;

typedef unsigned long __rlim64_t;

typedef unsigned int __id_t;

typedef signed long __time_t;

typedef unsigned int __useconds_t;

typedef signed long __suseconds_t;

typedef signed int __daddr_t;

typedef signed int __key_t;

typedef signed int __clockid_t;

typedef void  *__timer_t;

typedef signed long __blksize_t;

typedef signed long __blkcnt_t;

typedef signed long __blkcnt64_t;

typedef unsigned long __fsblkcnt_t;

typedef unsigned long __fsblkcnt64_t;

typedef unsigned long __fsfilcnt_t;

typedef unsigned long __fsfilcnt64_t;

typedef signed long __fsword_t;

typedef signed long __ssize_t;

typedef signed long __syscall_slong_t;

typedef unsigned long __syscall_ulong_t;

typedef __off64_t __loff_t;

typedef __quad_t  *__qaddr_t;

typedef char  *__caddr_t;

typedef signed long __intptr_t;

typedef unsigned int __socklen_t;

typedef __time_t time_t;

struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
  
};

typedef __pid_t pid_t;

struct sched_param {
  signed int __sched_priority;
  
};

struct __sched_param {
  signed int __sched_priority;
  
};

typedef unsigned long __cpu_mask;

typedef struct  {
  __cpu_mask __bits[(1024 / ((8 * (sizeof(__cpu_mask)))))];
  
} cpu_set_t;

extern signed int __sched_cpucount(size_t  __setsize, const cpu_set_t  * __setp) __attribute__((__nothrow__, __leaf__));

extern cpu_set_t  *__sched_cpualloc(size_t  __count) __attribute__((__nothrow__, __leaf__));

extern void __sched_cpufree(cpu_set_t  * __set) __attribute__((__nothrow__, __leaf__));

extern signed int sched_setparam(__pid_t  __pid, const struct sched_param  * __param) __attribute__((__nothrow__, __leaf__));

extern signed int sched_getparam(__pid_t  __pid, struct sched_param  * __param) __attribute__((__nothrow__, __leaf__));

extern signed int sched_setscheduler(__pid_t  __pid, signed int  __policy, const struct sched_param  * __param) __attribute__((__nothrow__, __leaf__));

extern signed int sched_getscheduler(__pid_t  __pid) __attribute__((__nothrow__, __leaf__));

extern signed int sched_yield(void) __attribute__((__nothrow__, __leaf__));

extern signed int sched_get_priority_max(signed int  __algorithm) __attribute__((__nothrow__, __leaf__));

extern signed int sched_get_priority_min(signed int  __algorithm) __attribute__((__nothrow__, __leaf__));

extern signed int sched_rr_get_interval(__pid_t  __pid, struct timespec  * __t) __attribute__((__nothrow__, __leaf__));

extern signed long __sysconf(signed int  );

typedef __clock_t clock_t;

struct tm {
  signed int tm_sec;
  signed int tm_min;
  signed int tm_hour;
  signed int tm_mday;
  signed int tm_mon;
  signed int tm_year;
  signed int tm_wday;
  signed int tm_yday;
  signed int tm_isdst;
  signed long __tm_gmtoff;
  const char  *__tm_zone;
  
};

extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));

extern time_t time(time_t  * __timer) __attribute__((__nothrow__, __leaf__));

extern double difftime(time_t  __time1, time_t  __time0) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern time_t mktime(struct tm  * __tp) __attribute__((__nothrow__, __leaf__));

extern size_t strftime(char  *__restrict  __s, size_t  __maxsize, const char  *__restrict  __format, const struct tm  *__restrict  __tp) __attribute__((__nothrow__, __leaf__));

extern struct tm  *gmtime(const time_t  * __timer) __attribute__((__nothrow__, __leaf__));

extern struct tm  *localtime(const time_t  * __timer) __attribute__((__nothrow__, __leaf__));

extern struct tm  *gmtime_r(const time_t  *__restrict  __timer, struct tm  *__restrict  __tp) __attribute__((__nothrow__, __leaf__));

extern struct tm  *localtime_r(const time_t  *__restrict  __timer, struct tm  *__restrict  __tp) __attribute__((__nothrow__, __leaf__));

extern char  *asctime(const struct tm  * __tp) __attribute__((__nothrow__, __leaf__));

extern char  *ctime(const time_t  * __timer) __attribute__((__nothrow__, __leaf__));

extern char  *asctime_r(const struct tm  *__restrict  __tp, char  *__restrict  __buf) __attribute__((__nothrow__, __leaf__));

extern char  *ctime_r(const time_t  *__restrict  __timer, char  *__restrict  __buf) __attribute__((__nothrow__, __leaf__));

extern char  *__tzname[2];

extern signed int __daylight;

extern signed long __timezone;

extern char  *tzname[2];

extern void tzset(void) __attribute__((__nothrow__, __leaf__));

extern signed int timespec_get(struct timespec  * __ts, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

typedef unsigned long pthread_t;

union pthread_attr_t {
  char __size[56];
  signed long __align;
  
};

typedef union pthread_attr_t pthread_attr_t;

typedef struct __pthread_internal_list {
  struct __pthread_internal_list  *__prev;
  struct __pthread_internal_list  *__next;
  
} __pthread_list_t;

typedef union  {
  struct __pthread_mutex_s {
    signed int __lock;
    unsigned int __count;
    signed int __owner;
    unsigned int __nusers;
    signed int __kind;
    signed short __spins;
    signed short __elision;
    __pthread_list_t __list;
    
  } __data;
  char __size[40];
  signed long __align;
  
} pthread_mutex_t;

typedef union  {
  char __size[4];
  signed int __align;
  
} pthread_mutexattr_t;

typedef union  {
  struct  {
    signed int __lock;
    unsigned int __futex;
    unsigned long long __total_seq;
    unsigned long long __wakeup_seq;
    unsigned long long __woken_seq;
    void  *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
    
  } __data;
  char __size[48];
  signed long long __align;
  
} pthread_cond_t;

typedef union  {
  char __size[4];
  signed int __align;
  
} pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef signed int pthread_once_t;

typedef signed long __jmp_buf[8];

enum  {
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};

enum  {
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
};

enum  {
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};

enum  {
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};

enum  {
  PTHREAD_PROCESS_PRIVATE,
  PTHREAD_PROCESS_SHARED
};

struct _pthread_cleanup_buffer {
  void ( *__routine)(void  * );
  void  *__arg;
  signed int __canceltype;
  struct _pthread_cleanup_buffer  *__prev;
  
};

enum  {
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE
};

enum  {
  PTHREAD_CANCEL_DEFERRED,
  PTHREAD_CANCEL_ASYNCHRONOUS
};

extern signed int pthread_create(pthread_t  *__restrict  __newthread, const pthread_attr_t  *__restrict  __attr, void  *( * __start_routine)(void  * ), void  *__restrict  __arg) __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 3)));

extern void pthread_exit(void  * __retval) __attribute__((__noreturn__));

extern signed int pthread_join(pthread_t  __th, void  * * __thread_return);

extern signed int pthread_detach(pthread_t  __th) __attribute__((__nothrow__, __leaf__));

extern pthread_t pthread_self(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern signed int pthread_equal(pthread_t  __thread1, pthread_t  __thread2) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern signed int pthread_attr_init(pthread_attr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_destroy(pthread_attr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getdetachstate(const pthread_attr_t  * __attr, signed int  * __detachstate) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setdetachstate(pthread_attr_t  * __attr, signed int  __detachstate) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getguardsize(const pthread_attr_t  * __attr, size_t  * __guardsize) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setguardsize(pthread_attr_t  * __attr, size_t  __guardsize) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getschedparam(const pthread_attr_t  *__restrict  __attr, struct sched_param  *__restrict  __param) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setschedparam(pthread_attr_t  *__restrict  __attr, const struct sched_param  *__restrict  __param) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_getschedpolicy(const pthread_attr_t  *__restrict  __attr, signed int  *__restrict  __policy) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setschedpolicy(pthread_attr_t  * __attr, signed int  __policy) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getinheritsched(const pthread_attr_t  *__restrict  __attr, signed int  *__restrict  __inherit) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setinheritsched(pthread_attr_t  * __attr, signed int  __inherit) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getscope(const pthread_attr_t  *__restrict  __attr, signed int  *__restrict  __scope) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setscope(pthread_attr_t  * __attr, signed int  __scope) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_attr_getstackaddr(const pthread_attr_t  *__restrict  __attr, void  * *__restrict  __stackaddr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2))) __attribute__((__deprecated__));

extern signed int pthread_attr_setstackaddr(pthread_attr_t  * __attr, void  * __stackaddr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1))) __attribute__((__deprecated__));

extern signed int pthread_attr_getstacksize(const pthread_attr_t  *__restrict  __attr, size_t  *__restrict  __stacksize) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_attr_setstacksize(pthread_attr_t  * __attr, size_t  __stacksize) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_setschedparam(pthread_t  __target_thread, signed int  __policy, const struct sched_param  * __param) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));

extern signed int pthread_getschedparam(pthread_t  __target_thread, signed int  *__restrict  __policy, struct sched_param  *__restrict  __param) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

extern signed int pthread_setschedprio(pthread_t  __target_thread, signed int  __prio) __attribute__((__nothrow__, __leaf__));

extern signed int pthread_once(pthread_once_t  * __once_control, void ( * __init_routine)(void)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_setcancelstate(signed int  __state, signed int  * __oldstate);

extern signed int pthread_setcanceltype(signed int  __type, signed int  * __oldtype);

extern signed int pthread_cancel(pthread_t  __th);

extern void pthread_testcancel(void);

typedef struct  {
  struct  {
    __jmp_buf __cancel_jmp_buf;
    signed int __mask_was_saved;
    
  } __cancel_jmp_buf[1];
  void  *__pad[4];
  
} __pthread_unwind_buf_t __attribute__((__aligned__));

struct __pthread_cleanup_frame {
  void ( *__cancel_routine)(void  * );
  void  *__cancel_arg;
  signed int __do_it;
  signed int __cancel_type;
  
};

extern void __pthread_register_cancel(__pthread_unwind_buf_t  * __buf);

extern void __pthread_unregister_cancel(__pthread_unwind_buf_t  * __buf);

extern void __pthread_unwind_next(__pthread_unwind_buf_t  * __buf) __attribute__((__noreturn__)) __attribute__((__weak__));

struct __jmp_buf_tag;

extern signed int __sigsetjmp(struct __jmp_buf_tag  * __env, signed int  __savemask) __attribute__((__nothrow__));

extern signed int pthread_mutex_init(pthread_mutex_t  * __mutex, const pthread_mutexattr_t  * __mutexattr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutex_destroy(pthread_mutex_t  * __mutex) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutex_trylock(pthread_mutex_t  * __mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutex_lock(pthread_mutex_t  * __mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutex_unlock(pthread_mutex_t  * __mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutex_getprioceiling(const pthread_mutex_t  *__restrict  __mutex, signed int  *__restrict  __prioceiling) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_mutex_setprioceiling(pthread_mutex_t  *__restrict  __mutex, signed int  __prioceiling, signed int  *__restrict  __old_ceiling) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern signed int pthread_mutexattr_init(pthread_mutexattr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutexattr_destroy(pthread_mutexattr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutexattr_getpshared(const pthread_mutexattr_t  *__restrict  __attr, signed int  *__restrict  __pshared) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_mutexattr_setpshared(pthread_mutexattr_t  * __attr, signed int  __pshared) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutexattr_getprotocol(const pthread_mutexattr_t  *__restrict  __attr, signed int  *__restrict  __protocol) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_mutexattr_setprotocol(pthread_mutexattr_t  * __attr, signed int  __protocol) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t  *__restrict  __attr, signed int  *__restrict  __prioceiling) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_mutexattr_setprioceiling(pthread_mutexattr_t  * __attr, signed int  __prioceiling) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_cond_init(pthread_cond_t  *__restrict  __cond, const pthread_condattr_t  *__restrict  __cond_attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_cond_destroy(pthread_cond_t  * __cond) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_cond_signal(pthread_cond_t  * __cond) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

extern signed int pthread_cond_broadcast(pthread_cond_t  * __cond) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));

extern signed int pthread_cond_wait(pthread_cond_t  *__restrict  __cond, pthread_mutex_t  *__restrict  __mutex) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_cond_timedwait(pthread_cond_t  *__restrict  __cond, pthread_mutex_t  *__restrict  __mutex, const struct timespec  *__restrict  __abstime) __attribute__((__nonnull__(1, 2, 3)));

extern signed int pthread_condattr_init(pthread_condattr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_condattr_destroy(pthread_condattr_t  * __attr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_condattr_getpshared(const pthread_condattr_t  *__restrict  __attr, signed int  *__restrict  __pshared) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern signed int pthread_condattr_setpshared(pthread_condattr_t  * __attr, signed int  __pshared) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_key_create(pthread_key_t  * __key, void ( * __destr_function)(void  * )) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern signed int pthread_key_delete(pthread_key_t  __key) __attribute__((__nothrow__, __leaf__));

extern void  *pthread_getspecific(pthread_key_t  __key) __attribute__((__nothrow__, __leaf__));

extern signed int pthread_setspecific(pthread_key_t  __key, const void  * __pointer) __attribute__((__nothrow__, __leaf__));

extern signed int pthread_atfork(void ( * __prepare)(void), void ( * __parent)(void), void ( * __child)(void)) __attribute__((__nothrow__, __leaf__));

void spawn_routine(void  *( * start_function)(void  * ), void  * args);

typedef struct __OpQueue {
  pthread_cond_t  *cond;
  struct __OpQueue  *next;
  
} OpQueue;



OpQueue  *_op_queue_new()
{

  {
    OpQueue  *tq = ((malloc)((sizeof(OpQueue))));;
    (((tq)->cond) = (((void *)0)));
    (((tq)->next) = (((void *)0)));
    return (tq);
  }
}

void _op_queue_free(OpQueue  * tq)
{

  {
    if ((((tq)->cond) != (((void *)0))))
    {
      {
        ((pthread_cond_destroy)(((tq)->cond)));
      }
    } else {
      
    }
    ((free)((tq)));
  }
}





void spawn_routine(void  *( * start_function)(void  * ), void  * args)
{

  {
    pthread_t thread;;
    ((pthread_create)((&(thread)), (((void *)0)), (start_function), (args)));
    return ;
  }
}













struct _IO_FILE;

typedef struct _IO_FILE FILE;

typedef struct _IO_FILE __FILE;

typedef struct  {
  signed int __count;
  union  {
    unsigned int __wch;
    char __wchb[4];
    
  } __value;
  
} __mbstate_t;

typedef struct  {
  __off_t __pos;
  __mbstate_t __state;
  
} _G_fpos_t;

typedef struct  {
  __off64_t __pos;
  __mbstate_t __state;
  
} _G_fpos64_t;

typedef __builtin_va_list __gnuc_va_list;

struct _IO_jump_t;

struct _IO_FILE;

typedef void _IO_lock_t;

struct _IO_marker {
  struct _IO_marker  *_next;
  struct _IO_FILE  *_sbuf;
  signed int _pos;
  
};

enum __codecvt_result {
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};

struct _IO_FILE {
  signed int _flags;
  char  *_IO_read_ptr;
  char  *_IO_read_end;
  char  *_IO_read_base;
  char  *_IO_write_base;
  char  *_IO_write_ptr;
  char  *_IO_write_end;
  char  *_IO_buf_base;
  char  *_IO_buf_end;
  char  *_IO_save_base;
  char  *_IO_backup_base;
  char  *_IO_save_end;
  struct _IO_marker  *_markers;
  struct _IO_FILE  *_chain;
  signed int _fileno;
  signed int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t  *_lock;
  __off64_t _offset;
  void  *__pad1;
  void  *__pad2;
  void  *__pad3;
  void  *__pad4;
  size_t __pad5;
  signed int _mode;
  char _unused2[(((15 * (sizeof(signed int))) - (4 * (sizeof(void *)))) - (sizeof(size_t)))];
  
};

typedef struct _IO_FILE _IO_FILE;

struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;

extern struct _IO_FILE_plus _IO_2_1_stdout_;

extern struct _IO_FILE_plus _IO_2_1_stderr_;

typedef __ssize_t __io_read_fn(void  * __cookie, char  * __buf, size_t  __nbytes);

typedef __ssize_t __io_write_fn(void  * __cookie, const char  * __buf, size_t  __n);

typedef signed int __io_seek_fn(void  * __cookie, __off64_t  * __pos, signed int  __w);

typedef signed int __io_close_fn(void  * __cookie);

extern signed int __underflow(_IO_FILE  * );

extern signed int __uflow(_IO_FILE  * );

extern signed int __overflow(_IO_FILE  * , signed int  );

extern signed int _IO_getc(_IO_FILE  * __fp);

extern signed int _IO_putc(signed int  __c, _IO_FILE  * __fp);

extern signed int _IO_feof(_IO_FILE  * __fp) __attribute__((__nothrow__, __leaf__));

extern signed int _IO_ferror(_IO_FILE  * __fp) __attribute__((__nothrow__, __leaf__));

extern signed int _IO_peekc_locked(_IO_FILE  * __fp);

extern void _IO_flockfile(_IO_FILE  * ) __attribute__((__nothrow__, __leaf__));

extern void _IO_funlockfile(_IO_FILE  * ) __attribute__((__nothrow__, __leaf__));

extern signed int _IO_ftrylockfile(_IO_FILE  * ) __attribute__((__nothrow__, __leaf__));

extern signed int _IO_vfscanf(_IO_FILE  *__restrict  , const char  *__restrict  , __gnuc_va_list  , signed int  *__restrict  );

extern signed int _IO_vfprintf(_IO_FILE  *__restrict  , const char  *__restrict  , __gnuc_va_list  );

extern __ssize_t _IO_padn(_IO_FILE  * , signed int  , __ssize_t  );

extern size_t _IO_sgetn(_IO_FILE  * , void  * , size_t  );

extern __off64_t _IO_seekoff(_IO_FILE  * , __off64_t  , signed int  , signed int  );

extern __off64_t _IO_seekpos(_IO_FILE  * , __off64_t  , signed int  );

extern void _IO_free_backup_area(_IO_FILE  * ) __attribute__((__nothrow__, __leaf__));

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE  *stdin;

extern struct _IO_FILE  *stdout;

extern struct _IO_FILE  *stderr;

extern signed int remove(const char  * __filename) __attribute__((__nothrow__, __leaf__));

extern signed int rename(const char  * __old, const char  * __new) __attribute__((__nothrow__, __leaf__));

extern FILE  *tmpfile(void);

extern char  *tmpnam(char  * __s) __attribute__((__nothrow__, __leaf__));

extern signed int fclose(FILE  * __stream);

extern signed int fflush(FILE  * __stream);

extern FILE  *fopen(const char  *__restrict  __filename, const char  *__restrict  __modes);

extern FILE  *freopen(const char  *__restrict  __filename, const char  *__restrict  __modes, FILE  *__restrict  __stream);

extern FILE  *fdopen(signed int  __fd, const char  * __modes) __attribute__((__nothrow__, __leaf__));

extern void setbuf(FILE  *__restrict  __stream, char  *__restrict  __buf) __attribute__((__nothrow__, __leaf__));

extern signed int setvbuf(FILE  *__restrict  __stream, char  *__restrict  __buf, signed int  __modes, size_t  __n) __attribute__((__nothrow__, __leaf__));

extern signed int fprintf(FILE  *__restrict  __stream, const char  *__restrict  __format, ...);

extern signed int printf(const char  *__restrict  __format, ...);

extern signed int sprintf(char  *__restrict  __s, const char  *__restrict  __format, ...) __attribute__((__nothrow__));

extern signed int vfprintf(FILE  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg);

extern signed int vprintf(const char  *__restrict  __format, __gnuc_va_list  __arg);

extern signed int vsprintf(char  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg) __attribute__((__nothrow__));

extern signed int snprintf(char  *__restrict  __s, size_t  __maxlen, const char  *__restrict  __format, ...) __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));

extern signed int vsnprintf(char  *__restrict  __s, size_t  __maxlen, const char  *__restrict  __format, __gnuc_va_list  __arg) __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));

extern signed int fscanf(FILE  *__restrict  __stream, const char  *__restrict  __format, ...);

extern signed int scanf(const char  *__restrict  __format, ...);

extern signed int sscanf(const char  *__restrict  __s, const char  *__restrict  __format, ...) __attribute__((__nothrow__, __leaf__));

extern signed int vfscanf(FILE  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg) __attribute__((__format__(__scanf__, 2, 0)));

extern signed int vscanf(const char  *__restrict  __format, __gnuc_va_list  __arg) __attribute__((__format__(__scanf__, 1, 0)));

extern signed int vsscanf(const char  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg) __attribute__((__nothrow__, __leaf__)) __attribute__((__format__(__scanf__, 2, 0)));

extern signed int fgetc(FILE  * __stream);

extern signed int getc(FILE  * __stream);

extern signed int getchar(void);

extern signed int getc_unlocked(FILE  * __stream);

extern signed int getchar_unlocked(void);

extern signed int fputc(signed int  __c, FILE  * __stream);

extern signed int putc(signed int  __c, FILE  * __stream);

extern signed int putchar(signed int  __c);

extern signed int putc_unlocked(signed int  __c, FILE  * __stream);

extern signed int putchar_unlocked(signed int  __c);

extern char  *fgets(char  *__restrict  __s, signed int  __n, FILE  *__restrict  __stream);

extern signed int fputs(const char  *__restrict  __s, FILE  *__restrict  __stream);

extern signed int puts(const char  * __s);

extern signed int ungetc(signed int  __c, FILE  * __stream);

extern size_t fread(void  *__restrict  __ptr, size_t  __size, size_t  __n, FILE  *__restrict  __stream);

extern size_t fwrite(const void  *__restrict  __ptr, size_t  __size, size_t  __n, FILE  *__restrict  __s);

extern signed int fseek(FILE  * __stream, signed long  __off, signed int  __whence);

extern signed long ftell(FILE  * __stream);

extern void rewind(FILE  * __stream);

extern signed int fgetpos(FILE  *__restrict  __stream, fpos_t  *__restrict  __pos);

extern signed int fsetpos(FILE  * __stream, const fpos_t  * __pos);

extern void clearerr(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern signed int feof(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern signed int ferror(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern void perror(const char  * __s);

extern signed int fileno(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern char  *ctermid(char  * __s) __attribute__((__nothrow__, __leaf__));

extern void flockfile(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern signed int ftrylockfile(FILE  * __stream) __attribute__((__nothrow__, __leaf__));

extern void funlockfile(FILE  * __stream) __attribute__((__nothrow__, __leaf__));
typedef struct __attribute__(()) _template_Channel_builtin__signed_int_ {
  signed int v;
  signed int closed;
  OpQueue  *recvq;
  OpQueue  *sendq;
  pthread_mutex_t lock;
  pthread_cond_t vcond;
  
} _template_Channel_builtin__signed_int_;


typedef struct __filter_args {
  _template_Channel_builtin__signed_int_  *in;
  _template_Channel_builtin__signed_int_  *out;
  signed int prime;
  
} filter_args;




static signed int _template_try_chan_send_builtin__signed_int_(_template_Channel_builtin__signed_int_  * ch, signed int  v)
{

  {
    pthread_cond_t  *recv_cond = (((ch)->recvq)->cond);;
    if (((recv_cond) != (((void *)0))))
    {
      {
        (((ch)->recvq) = (((ch)->recvq)->next));
        if ((((ch)->recvq) == (((void *)0))))
        {
          {
            (((ch)->recvq) = ((_op_queue_new)()));
          }
        } else {
          
        }
        (((ch)->v) = (v));
        ((pthread_cond_signal)((recv_cond)));
        return 1;
      }
    } else {
      
    }
    
    return 0;
  }
}
static void _template_chan_send_builtin__signed_int_(_template_Channel_builtin__signed_int_  * ch, signed int  v)
{

  {
    ((pthread_mutex_lock)((&(((ch)->lock)))));
    if (((_template_try_chan_send_builtin__signed_int_)((ch), (v))))
    {
      {
        ((pthread_mutex_unlock)((&(((ch)->lock)))));
        return ;
      }
    } else {
      
    }
    OpQueue  *send_lock = ((ch)->sendq);;
    while ((((send_lock)->next) != (((void *)0))))
    {
      {
        ((send_lock) = ((send_lock)->next));
      }
    }
    (((send_lock)->next) = ((_op_queue_new)()));
    pthread_cond_t cond = {{0, 0, 0, 0, 0, ((void *)0), 0, 0}};;
    (((send_lock)->cond) = (&(cond)));
    ((pthread_cond_wait)(((send_lock)->cond), (&(((ch)->lock)))));
    ((_op_queue_free)((send_lock)));
    (((ch)->v) = (v));
    ((pthread_cond_signal)((&(((ch)->vcond)))));
    ((pthread_mutex_unlock)((&(((ch)->lock)))));
    return ;
  }
}

void  *generate(void  * args)
{

  {
    _template_Channel_builtin__signed_int_  *ch = ((_template_Channel_builtin__signed_int_ *)(args));;
    signed int i = 2;;
    while (1)
    {
      {
        ((_template_chan_send_builtin__signed_int_)((ch), (i)));
        ((i)++);
      }
    }
  }
}




static signed int _template_try_chan_recv_builtin__signed_int_(_template_Channel_builtin__signed_int_  * ch)
{

  {
    pthread_cond_t  *send_cond = (((ch)->sendq)->cond);;
    if (((send_cond) != (((void *)0))))
    {
      {
        (((ch)->sendq) = (((ch)->sendq)->next));
        if ((((ch)->sendq) == (((void *)0))))
        {
          {
            (((ch)->sendq) = ((_op_queue_new)()));
          }
        } else {
          
        }
        ((pthread_cond_signal)((send_cond)));
        ((pthread_cond_wait)((&(((ch)->vcond))), (&(((ch)->lock)))));
        return 1;
      }
    } else {
      
    }
    return 0;
  }
}
static signed int _template_chan_recv_builtin__signed_int_(_template_Channel_builtin__signed_int_  * ch)
{

  {
    ((pthread_mutex_lock)((&(((ch)->lock)))));
    if (((_template_try_chan_recv_builtin__signed_int_)((ch))))
    {
      {
        signed int ret_v = ((ch)->v);;
        ((pthread_mutex_unlock)((&(((ch)->lock)))));
        return (ret_v);
      }
    } else {
      
    }
    OpQueue  *recv_lock = ((ch)->recvq);;
    while ((((recv_lock)->next) != (((void *)0))))
    {
      {
        ((recv_lock) = ((recv_lock)->next));
      }
    }
    (((recv_lock)->next) = ((_op_queue_new)()));
    pthread_cond_t cond = {{0, 0, 0, 0, 0, ((void *)0), 0, 0}};;
    (((recv_lock)->cond) = (&(cond)));
    ((pthread_cond_wait)(((recv_lock)->cond), (&(((ch)->lock)))));
    ((_op_queue_free)((recv_lock)));
    signed int ret_v = ((ch)->v);;
    ((pthread_mutex_unlock)((&(((ch)->lock)))));
    return (ret_v);
  }
}


void  *filter(void  * args)
{

  {
    filter_args  *f_args = ((filter_args *)(args));;
    _template_Channel_builtin__signed_int_  *in = ((f_args)->in);;
    _template_Channel_builtin__signed_int_  *out = ((f_args)->out);;
    signed int prime = ((f_args)->prime);;
    while (1)
    {
      {
        signed int i = ((_template_chan_recv_builtin__signed_int_)((in)));;
        if (((((i) % (prime))) != 0))
        {
          {
            ((_template_chan_send_builtin__signed_int_)((out), (i)));
          }
        } else {
          
        }
      }
    }
  }
}




static _template_Channel_builtin__signed_int_  *_template_chan_open_builtin__signed_int_()
{

  {
    pthread_mutex_t lock = {{0, 0, 0, 0, 0, 0, 0, {0, 0}}};;
    pthread_cond_t cond = {{0, 0, 0, 0, 0, ((void *)0), 0, 0}};;
    _template_Channel_builtin__signed_int_  *c = ((malloc)((sizeof(_template_Channel_builtin__signed_int_))));;
    (((c)->recvq) = ((_op_queue_new)()));
    (((c)->sendq) = ((_op_queue_new)()));
    (((c)->lock) = (lock));
    (((c)->vcond) = (cond));
    return (c);
  }
}




signed int main(signed int  argc, char  * * argv)
{

  {
    _template_Channel_builtin__signed_int_  *ch1 = ((_template_chan_open_builtin__signed_int_)());;
    ((spawn_routine)((generate), (ch1)));
    signed int i;;
    for(((i) = 1); ((i) < 101); ((i)++))
    {
      {
        signed int prime = ((_template_chan_recv_builtin__signed_int_)((ch1)));;
        ((printf)("The %dth prime is: %d\n", (i), (prime)));
        _template_Channel_builtin__signed_int_  *ch2 = ((_template_chan_open_builtin__signed_int_)());;
        filter_args  *f_args = ((malloc)((sizeof(filter_args))));;
        (((f_args)->in) = (ch1));
        (((f_args)->out) = (ch2));
        (((f_args)->prime) = (prime));
        ((spawn_routine)((filter), (f_args)));
        ((ch1) = (ch2));
      }
    }
  }
}
