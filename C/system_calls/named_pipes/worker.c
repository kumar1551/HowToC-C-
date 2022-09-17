#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO_NAME "office_report"
int main(void)
{
	int fd;
	
	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
	printf("Waiting for Manager...\n");
	fd = open(FIFO_NAME, O_WRONLY);

    dup2(fd, 1);
	
	execlp("ls", "ls", "-l", NULL);
	
 	return 0;
}