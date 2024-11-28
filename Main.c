#include "Main.h"  
#include "enseah_terminal.h"  

void write_str(const char *str) {
    write(STDOUT_FILENO, str, strlen(str));
}

void enseah_terminal() {
    char command[MAX_COMMAND_LEN];
    char *args[MAX_ARGS];
    
    while (1) {
        // Display the prompt
        write_str("enseah% ");
        
        // Read the command
        ssize_t bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LEN); // Put the STDIN_FILENO in command.

        // Quit if CTRL+D is pressed
        if (bytes_read ==  0) {          
            write_str("\nBye!\n");
            write(STDOUT_FILENO, bytes_read, strlen(bytes_read));
            break;
        }

        // Remove line break (ENTER)
        command[bytes_read - 1] = '\0';

        // Check if user wants to exit
        if (strcmp(command, "exit") == 0) {
            write_str("Exiting enseah...\n");
            break;
        }


        // Create a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            write_str("Error: Fork failed\n");
            continue;
        }

        if (pid == 0) {
            // Child : Execute the process
            execvp(args[0], args);
            write_str("Error: Command not found\n");
            exit(EXIT_FAILURE);
        } else {
            // Parent : wait the end of the child process
            int status;
            waitpid(pid, &status, 0);
        }
    }
}


int main() {
    write_str("Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n");
    enseah_terminal();
    return 0;
}
