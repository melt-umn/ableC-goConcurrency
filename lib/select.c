// select {
// case <-ch:
if (try_chan_recv(ch)) {
    pthread_mutex_unlock(&(ch->lock));
    //...
// case int v = <-ch:
} else if (try_chan_recv(ch)) {
    int v = *(*int)ch->v;
    pthread_mutex_unlock(&(ch->lock));
    //...
// case ch <- v:
} else if (try_chan_send(ch, v)) {
    pthread_mutex_unlock(&(ch->lock));
    //...
// default:
} else {
    //...
}
//}