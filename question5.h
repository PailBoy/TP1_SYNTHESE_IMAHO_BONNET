#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 1024
#define msg_time " | %d ms] "

extern struct timespec start;
extern struct timespec end ;

void print_time(int time);
void start_timer();
void end_timer();
int get_time();
