#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

 
void* doSomething( void* arg ){
 
  printf( "I am inside the thread\n");
  
  //waits here until signal is sent to cond by main
  printf( "Thread is waiting for main\n");
  pthread_cond_wait(&cond,&mtx);
  
  printf( "Thread woken up by main.\n");
  
  return NULL;
}
 
int main(){
  //create the thread
  pthread_t thread;
  pthread_create(&thread, NULL, doSomething, NULL );
  
  printf( "Hello World! It's me, main!\n");
  
  //main goes to sleep
  printf("Main is going to sleep\n");
  sleep(2);
  
  //main signals thread to wake up
  printf("Main has awoken. Good morning thread!\n");
  pthread_cond_signal(&cond);
  
  //wait until thread completes
  pthread_join(thread, NULL );
  printf( "In main: thread has completed\n");
}