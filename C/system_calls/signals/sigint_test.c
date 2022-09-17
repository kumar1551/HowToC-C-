#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int sigint_count = 0;

void sigint_handler(int signum){
	printf("\nInterrupt Signal, count = %d\n", sigint_count + 1);
	if (++sigint_count == 5 - 1) signal(SIGINT, SIG_DFL);
}


int main(){

	signal(SIGINT, sigint_handler);
	
	while(1){
		printf("Infinite Loop\n");
		sleep(2);
	}

}
