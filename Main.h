#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGS 100

void write_str(const char *str);
void enseah_terminal();
int main();
