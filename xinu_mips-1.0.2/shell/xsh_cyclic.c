#include <kernel.h>
#include <shell.h>
#include <stdio.h>
#include <ctype.h>
#include <clock.h>
//#include <sys/times.h>//1
//#include <unistd.h>//1

#define SLOTX_ 6
#define CYCLEX_ 2
#define SLOT_T 5000
#define THREAD_COUNT 4
#define STORE_COUNT 8


int tps_,cycle_=0,slot_=0;
//clock_t now, then;
//struct tms n;

void task1_(void) {
 printf("Task 1 running\n");
 sleep(1000);
}

void task2_(void) {
  printf("Task 2 running\n");
  sleep(1000);
}

void task3_(void) {
  printf("Task 3 running\n");
  sleep(1000);
}
void task4_(void) {
  printf("Task 3 running\n");
  sleep(1000);
}

void task5_(void) {
  printf("Task 3 running\n");
  sleep(1000);
}

void burn_ (void){
	//clock_t bstart =times(&n);
	//while (((now=time(&n))-then) < SLOT_T* tps/1000 ) {
	/*burn time here*/
	printf("burning\n");	

//}
//printf("burn time = %2.2dms\n\n",(times(&n)-bstart)*1000/tps);
//	then = now;
//	cycle =CYCLEX;
}


void (*ttable_[SLOTX_][CYCLEX_])(void) = {
{task1_,task1_},
{task3_,task2_},
{task1_,task1_},
{task2_,burn_},
{task1_,task1_},
{burn_,burn_}};

/*
{task1_,task2_,burn_,burn_,burn_},
{task1_,task3_,burn_,burn_,burn_},
{task1_,task4_,burn_,burn_,burn_},
{burn_,burn_,burn_,burn_,burn_}};
*/
command xsh_cyclic(ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[])
{	
	//tps= sysconf(_SC_CLK_TCK);
	//printf("clock ticks/sec =%d\n\n",tps_);
	while(1){

      printf("\n*****Hyperperiod - 12*****  \n");
      for (slot_=0; slot_ <SLOTX_; slot_++)
       { printf ("\n	Frame size - 2 \n");
        for (cycle_=0; cycle_<CYCLEX_; cycle_++)
          (*ttable_[slot_][cycle_])();
        }
	}

  uchar test_array[THREAD_COUNT * STORE_COUNT];
   int a_tid_, b_tid_,c_tid_;

  int a_prio_ = 3, b_prio_ = 2, c_prio_ = 1;
  int shared = 0;

  ready(a_tid_ = create(task1_, 0, a_prio_, "Task 1", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);
  ready(b_tid_ = create(task2_, 0, b_prio_, "Task 2", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);
  ready(c_tid_ = create(task3_, 0, c_prio_, "Task 3", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);


  	if (a_prio_ > b_prio_) fprintf(stdout, "Task 1 has a higher priority than Task 2.\n");
  	else if (a_prio_ < b_prio_) fprintf(stdout, "Task 2 has a higher priority than Task 1 .\n");
  	else if (a_prio_ < c_prio_) fprintf(stdout, "Task 3 has a higher priority than Task 1.\n");
  	else if (a_prio_ > c_prio_) fprintf(stdout, "Task 1 has a higher priority than Task 3.\n");
  	else if (b_prio_ > c_prio_) fprintf(stdout, "Task 2 has a higher priority than Task 3.\n");
  	else if (b_prio_ < c_prio_) fprintf(stdout, "Task 3 has a higher priority than Task 2.\n");
  	else fprintf(stdout, "Task A and Task B have the same priority.\n");

	fprintf(stdout,"Thread ID of Task 1 is %d.\nThread ID of Task 2 is %d.\nThread ID of Task 3 is %d.\n", a_tid_, b_tid_, c_tid_);

   	return 0;
}

