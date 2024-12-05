#include "question1.h"
#include "question2.h"
#include "question3.h"

int main(){
    welcome();
    while(1){
        print_prompt();
        print_percentage();
        char * command = read_command();
        if (command_exit(command) == 1) { //if the instruction is exit, we stop
            exit(0);
        }
        if (strlen(read_command()) == 0){
            write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
            break;
        }
        execute_command(command); 
    }
    
}
