#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signal_number){

    switch (signal_number) {
        
        case SIGINT:
            printf("Received Signal is SIGINT, signal_number = %d\n", signal_number);
            break;
        
        case SIGHUP:
            printf("Received Signal is SIGHUP, signal_number = %d\n", signal_number);
            break;
        
        case SIGTERM:
            printf("Received Signal is SIGTERM, signal_number = %d\n", signal_number);
            break;
        
        case SIGQUIT:{
            
            printf("Received Signal is SIGQUIT, signal_number = %d\n", signal_number);
            exit(0);
            break;
        }
            
        default:
            break;
    }

}

int main() {

    signal(SIGINT, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGQUIT, signal_handler);

    while(1) {
        printf("Programming Running\n");
        sleep(3);
    }

    return 0;
}
