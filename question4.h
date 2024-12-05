#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define MAXSIZE 1024
#define MSG_EXIT "[exit:%d] "
#define MSG_SIGN "[sign:%d] "

void print_status(int status);
void write_message(char *message, int val);
