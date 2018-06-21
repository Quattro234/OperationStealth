#include <time.h>
#include <stdio.h>


int main() {
  clock_t t;
  int waitingTime;

  printf("how many minutes will you waiting?   \n");
  scanf("%d",&waitingTime);

  t = clock(); //record start time here
  waitingTime = waitingTime * CLOCKS_PER_SEC * 60;
  //calculates the number of cycles needed until required time is elapsed
  printf("start waiting.. \n");

  while(clock() - t < waitingTime){}
  //waits till required time has passed

  printf("finished. ");
  for(int i; i < 2; i++ ){printf(" \a");}

return 0;
}
