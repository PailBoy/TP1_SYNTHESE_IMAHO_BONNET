#include "question2.h"
#include "main.h"


// Read the command
void read_command(char *command){
    int bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LEN);
    if (bytes_read > 0){
        if (command[bytes_read-1] == '\n') {
            command[bytes_read-1] = '\0';
        } else {
            command[bytes_read] = '\0';
        }
    }
    else {
        EXIT_FAILURE;
    }
}

//Execute the command
void execute_command(char *command, int *status){
    pid_t pid = fork();

    if (pid == 0) { // child execute command
        execlp(command, command, NULL);
        exit(1); //make sure to finish child process, in order to avoid child process "superposition"
    }
    else { //father : waiting for child to finish
        wait(status);
    }
}
