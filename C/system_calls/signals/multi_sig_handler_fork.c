#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int signal_number){

    switch (signal_number) {
        
        case SIGINT:
            printf("Received SIGINT, signal_number = %d\n", signal_number);
            break;
        
        case SIGHUP:
            printf("Received SIGHUP, signal_number = %d\n", signal_number);
            break;
        
        case SIGTERM:
            printf("Received SIGTERM, signal_number = %d\n", signal_number);
            break;
        
        case SIGQUIT:{
            
            printf("Received SIGQUIT, signal_number = %d\n", signal_number);
            exit(0);
            break;
        }
            
        default:
            break;
    }

}

int main() {

    int pid, i;

    signal(SIGINT, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGQUIT, SIG_DFL);


    pid = fork();


    if (pid == 0) {

        printf ("This is Child ( PID = %d)\n", getpid());

        for (i = 0; i < 12; i++) {
            printf("Child Running\n");
            sleep(1);
        }
    }
    else {

        sleep(2);
        printf("\nParent sending SIGINT\n");
        kill(pid, SIGINT);

        sleep(2);
        printf("\nParent sending SIGHUP\n");
        kill(pid, SIGHUP);
        
        sleep(2);
        printf("\nParent sending SIGTERM\n");
        kill(pid, SIGTERM);
        
        sleep(2);
        printf("\nParent sending SIGQUIT\n");
        kill(pid, SIGQUIT);

        wait(NULL);
        printf("\nChild Terminated, This is Parent( PID = %d)\n", getpid());
        

    }



    return 0;
}



