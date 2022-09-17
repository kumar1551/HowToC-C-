#include <stdio.h>
#include <unistd.h>

int main(){

	int fds1[2], fds2[2];

	int process;

	char msg_pipe1[20] = "Hi, Who are you?";
	char msg_pipe2[20] = "Hello, I'm Vaibhav";

	char msg_buffer[20];

	if (pipe(fds1) == -1){
		printf("Unable to create pipe 1 \n");
		return 1;
	}

	if (pipe(fds2) == -1){
		printf("Unable to create pipe 2 \n");
		return 1;
	}


	process = fork();

	// Parent process
	if (process != 0){

		printf("\n");


		close(fds1[0]); // Close the unwanted pipe1 read side
		close(fds2[1]); // Close the unwanted pipe2 write side

		printf("Parent writing to pipe 1, Message is -> %s\n\n", msg_pipe1);
		write(fds1[1], msg_pipe1, sizeof(msg_pipe1)); // parent writing to pipe 1

		read(fds2[0], msg_buffer, sizeof(msg_buffer)); // parent reading from pipe 2
		printf("Parent reading from pipe 2, Message is -> %s\n\n", msg_buffer);
	}
	// child process
	else{

		printf("\n");


		close(fds1[1]); // Close the unwanted pipe1 write side
		close(fds2[0]); // Close the unwanted pipe2 read side

		read(fds1[0], msg_buffer, sizeof(msg_buffer)); // Child reading from pipe 1
		printf("Child reading from pipe 1, Message is -> %s\n\n", msg_buffer);

		printf("Child writing to pipe 2, Message is -> %s\n\n", msg_pipe2);
		write(fds2[1], msg_pipe2, sizeof(msg_pipe2)); // Child Writing to pipe 2
	}
	return 0;
}
