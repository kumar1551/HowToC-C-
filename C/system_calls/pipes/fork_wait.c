#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){

	system("clear");	
	
	printf("Process ID: %d, Owner ID: %d\n", (int) getpid(), (int) geteuid());

   	pid_t pid = fork();
   	printf("fork returned: %d\n", (int) pid);

    if (pid < 0) {
   		perror("Forking failed");
   	}
    if (pid == 0) {
   		printf("This is child process PID: %d, Its Parent's PID: %d\n", (int) getpid(), (int) getppid());
		printf("Child process is exiting\n");
		exit(0);
	}
   
   	printf("This is parent process waiting for the child process to end\n");
    wait(NULL);
    printf("parent process is exiting\n");
    return(0);
}
