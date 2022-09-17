#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include<sys/wait.h>


int main(void){
    int fds[2];
    
    char msg_buffer[30];
    char msg_child[30] = "I'm a Child Process.";


    
    if (pipe(fds) == -1) {
        perror("pipe");
        exit(1);
    }
    
    
    if (fork() != 0)
    {
        close(fds[0]); // closing unwanted reads

        printf("PARENT writing to the pipe, Message is -> \"%s\" \n", msg_child);
        write(fds[1], msg_child, sizeof(msg_child));
        printf("PARENT: exiting\n\n");
        exit(0);
    }
    else
    {
        close(fds[1]); // closing unwanted writes in pipe

        read(fds[0], msg_buffer, sizeof(msg_buffer));
        printf("Child is reading from pipe, Message is -> \"%s\" \n", msg_buffer);
        wait(NULL);
    }
    return 0;
}