/*
This is an example of creating a pthread with two arguments of different types;
*/

#include <pthread.h>
#include <stdio.h>

//the function to execute in the threads
//printNumber takes args int x and char y;
void* printNumber(void* args){

  int x = *(((int**) args)[0]);
  char* y = *(((char***) args)[1]);
  
  printf("Inside thread with x=%d and y=%s\n",x,y);
}

int main(){
  //set up arguments for thread
  pthread_t thread;
  int x = 5;
  char* y = "This is a test string";
  void* args[2];
  args[0] = &x;
  args[1] = &y;
  
  //creates thread
  pthread_create(&thread, NULL, printNumber, &args);
  
  //ends the thread
  pthread_join(thread, NULL);
  printf("Thread completed.\n");
  
}