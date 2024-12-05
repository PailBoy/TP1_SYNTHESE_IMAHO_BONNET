#include "question2.h"
#include "main.h"
#define MAX_COMMAND_LEN 1024


// Read the command
char * read_command(){
    char * command = malloc(MAX_COMMAND_LEN);
    int bytes_read = read(STDIN_FILENO, command, 1024);
    if (bytes_read > 0){
        if (command[bytes_read-1] == '\n') {
            command[bytes_read-1] = '\0';
        } else {
            command='\0';
        }
    }
    return command;
}

//Execute the command
void execute_command(char *command){
    int status;
    pid_t pid = fork();
    if (pid == 0) { // child execute command
        execlp(command, command, NULL);
        exit(1); //make sure to finish child process, in order to avoid child process "superposition"
    }
    else { //father : waiting for child to finish
        waitpid(pid, &status,0);
    }
}
