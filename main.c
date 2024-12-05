#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"
#include "question5.h"


int main(){
    int status = 0;
    welcome();
    
    while(1){
        print_prompt();
        print_status(status);
        print_time(get_time());
        print_percentage();
        char * command = read_command();
        if (command_exit(command) == 1) { //if the instruction is exit, we stop
            exit(0);
        }
        start_timer();
        status = execute_command(command); 
        end_timer();
    }
}
