/*
This is an example of creating a pthread with no arguments
*/

#include <pthread.h>
#include <stdio.h>

//the simple function
void* print(void* args){
  printf("Inside thread.\n");
}

int main(){
  //create thread
  pthread_t thread;
  pthread_create(&thread, NULL, print, NULL);
  
  //ends the thread
  pthread_join(thread, NULL);
  printf("Thread completed.\n");
}