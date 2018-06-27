#include <time.h>
#include <stdio.h>
#include <csignal>
#include <iostream>

void signalHandler(int signum) {
  printf("\ninterrupt signal %d received\a", signum);

  exit(signum);
}

int main() {

  signal(SIGINT, signalHandler);
  clock_t start;

  int waitingTime;

  printf("how many minutes will you waiting?   \n");
  scanf("%d",&waitingTime);

  start = clock(); //record start time here
  waitingTime = waitingTime * CLOCKS_PER_SEC * 60;
  //calculates the number of cycles needed until required time is elapsed
  printf("start waiting.. \n\n");

  while(clock() - start < waitingTime + 1) {
    printf("\r %d seconds have passed.", (clock()-start)/(CLOCKS_PER_SEC));
}
  //waits till required time has passed
  printf("\n\n\afinished. \a");

return 0;
}
