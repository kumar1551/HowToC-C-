#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>


#define FILE_NAME "student_info"

#define REQUEST_FIFO "client_request"

#define RESPONSE_FIFO "server_response"


int main(void)
{
    char res[125];
    int num, fdc, fds;

    


    mknod(REQUEST_FIFO, S_IFIFO | 0666, 0);
    
    
    printf("Waiting for server Connection...\n");
    
    fdc = open(REQUEST_FIFO, O_WRONLY);
    // fds = open(RESPONSE_FIFO, O_RDONLY);

    if ((num = write(fdc, FILE_NAME, strlen(FILE_NAME))) == -1)
        perror("write");
    else
        printf("client requested  \"%s\" file \n", FILE_NAME);


    mknod(RESPONSE_FIFO, S_IFIFO | 0666, 0);
    printf("Waiting for server Response...\n");
    fds = open(RESPONSE_FIFO, O_RDONLY);

    if ((num = read(fds, res, 125)) == -1)
        perror("read");
    else
    {
        res[num] = '\0';
        printf("Server Response:\n\"%s\"\n",res);
    }


    return 0;
}