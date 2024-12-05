#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define msg_welcome "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define prompt "enseash"
#define percentage "% "

void welcome();
void print_prompt();
void welcome_message();
void print_percentage();
