#include "question1.h"


void welcome_msg() {
    write(STDOUT_FILENO, msg_welcome, sizeof(msg_welcome));
}

void print_prompt() {
    write(STDOUT_FILENO, prompt, sizeof(prompt));
}

void print_percentage() {
    write(STDOUT_FILENO, percentage, sizeof(percentage));
}

void welcome() {
    welcome_msg();
    print_prompt();
    print_percentage();
}
