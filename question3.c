#include "question3.h"

int command_exit(char *command) {
    if (strcmp(command, "exit") == 0) {
        write(STDOUT_FILENO, "Exiting enseash...\n", strlen("Exiting enseash...\n"));
        return 1;
    }
    
    return 0;
}
