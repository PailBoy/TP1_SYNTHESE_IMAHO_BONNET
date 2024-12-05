#include "question5.h"
#include "question4.h"

struct timespec start;
struct timespec end;

void print_time(int time) {
    write_message(msg_time, time);
}

void start_timer() {
    clock_gettime(CLOCK_MONOTONIC, &start);
}

void end_timer() {
    clock_gettime(CLOCK_MONOTONIC, &end);
}

int get_time() {
    return ((int) ((double)(end.tv_sec - start.tv_sec)*1e3 + (double)(end.tv_nsec - start.tv_nsec) / 1e6)) ;
}
