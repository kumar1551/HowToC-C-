#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int pid, status;

void child_handler(int sig_num) {

    printf("\nSIGCHLD: Child process terminated, PID = %d\n\n", pid);

    if (WIFEXITED(status)) {

        printf("Exit status of the child was %d\n", WEXITSTATUS(status));
        printf("status of the child was %d\n", status);
        printf("wifexited status of the child was %d\n", WIFEXITED(status));
    }
}


int main() {
    int i;
    pid = fork();

    if (pid == 0) {
        printf("I'm Child (PID = %d) Exiting after 5 seconds\n", getpid());
        
        for(i = 0; i < 5; i++) {
            printf(". \n");
            sleep(1);
        }
    }
    else {

        signal(SIGCHLD, child_handler);

        printf("I'm Parent( PID = %d), Waiting for Child( PID = %d) to Terminate\n\n", getpid(), pid);
        
        waitpid(pid, &status, 0);
        
        printf("\nI'm parent process, PID = %d\n", getpid());
    }

    return 0;
}