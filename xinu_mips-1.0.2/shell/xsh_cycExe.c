#include <kernel.h>
#include <shell.h>
#include <stdio.h>
#include <ctype.h>
#include <clock.h>

#define SLOTX 10
#define CYCLEX 2
#define SLOT_T 5000
#define THREAD_COUNT 3
#define STORE_COUNT 8


int tps,cycle=0,slot=0;

void task1(void) {
 printf("Task 1 running\n");
 sleep(1000);
}

void task2(void) {
  printf("Task 2 running\n");
  sleep(1000);
}

void task3(void) {
  printf("Task 3 running\n");
  sleep(1000);
}
void task4(void) {
  printf("Task 4 running\n");
  sleep(1000);
}

void burn(void) { printf ("burning \n ");}

void (*ttable[SLOTX][CYCLEX])(void) = {
{task1,task3},
{task2,task2},
{task1,burn},
{task4,task4},
{task2,task2},
{task1,burn},
{task2,task2},
{task1,burn},
{task2,task2},
{task1,burn}};

/*
{task1,task1,task2,task2},
{task3,task3,task3,task3},
{task2,task2,task1,task1},
{task3,task3,task3,task3},
{task2,task2,task1,task1},
{task2,task2,burn,burn}};
*/
command xsh_cycExe(ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[])
{
	//tps=sysconf(_SC_CLK_TCK);
	//printf("clock ticks/sec =%d\n\n",tps_);
	while(1){
      	printf(" \n ****** Hyperperiod - 20 ****** \n");
      		for (slot=0; slot <SLOTX; slot++)
        	{ printf ("\n Frame size - 2 \n");
        		for (cycle=0; cycle<CYCLEX; cycle++)
          		(*ttable[slot][cycle])();
        	}
	}

  uchar test_array[THREAD_COUNT * STORE_COUNT];
   int a_tid, b_tid,c_tid;

  int a_prio = 3, b_prio = 2, c_prio = 1;
  int shared = 0;

  ready(a_tid = create(task1, 0, a_prio, "Task 1", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);
  ready(b_tid = create(task2, 0, b_prio, "Task 2", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);
  ready(c_tid = create(task3, 0, c_prio, "Task 3", 3, STORE_COUNT, test_array, &shared), RESCHED_NO);


  	if (a_prio > b_prio) fprintf(stdout, "Task 1 has a higher priority than Task 2.\n");
  	else if (a_prio < b_prio) fprintf(stdout, "Task 2 has a higher priority than Task 1 .\n");
  	else if (a_prio < c_prio) fprintf(stdout, "Task 3 has a higher priority than Task 1.\n");
  	else if (a_prio > c_prio) fprintf(stdout, "Task 1 has a higher priority than Task 3.\n");
  	else if (b_prio > c_prio) fprintf(stdout, "Task 2 has a higher priority than Task 3.\n");
  	else if (b_prio < c_prio) fprintf(stdout, "Task 3 has a higher priority than Task 2.\n");
  	else fprintf(stdout, "Task A and Task B have the same priority.\n");

	fprintf(stdout,"Thread ID of Task 1 is %d.\nThread ID of Task 2 is %d.\nThread ID of Task 3 is %d.\n", a_tid, b_tid, c_tid);

   	return 0;
}

