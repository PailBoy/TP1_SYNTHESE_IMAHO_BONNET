#include "Main.h"   

void write_str(const char *str) {
    write(STDOUT_FILENO, str, strlen(str));
}

void enseah_terminal() {
    char command[MAX_COMMAND_LEN];
    char *args[MAX_ARGS];
    
    while (1) {
        // Afficher le prompt
        write_str("enseah> ");
        
        // Lire la commande
        ssize_t bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LEN - 1);
        if (bytes_read <= 0) {
            write_str("\nBye!\n");
            break;
        }

        // Retirer le saut de ligne
        command[bytes_read - 1] = '\0';

        // Vérifier si l'utilisateur veut quitter
        if (strcmp(command, "exit") == 0) {
            write_str("Exiting enseah...\n");
            break;
        }

        // Tokeniser la commande en arguments
        int arg_count = 0;
        char *token = strtok(command, " ");
        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Créer un processus enfant pour exécuter la commande
        pid_t pid = fork();
        if (pid < 0) {
            write_str("Error: Fork failed\n");
            continue;
        }

        if (pid == 0) {
            // Enfant : exécuter la commande
            execvp(args[0], args);
            write_str("Error: Command not found\n");
            exit(EXIT_FAILURE);
        } else {
            // Parent : attendre la fin du processus enfant
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    write_str("Welcome to enseah terminal!\n");
    enseah_terminal();
    return 0;
}
