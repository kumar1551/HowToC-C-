#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>


#define CLIENT_REQUEST_FIFO "client_1_request"

#define CLIENT_REQUEST_DATA "Hello Server! This is Client 1"

#define SERVER_FIFO "well_known_server_response"


int main(void)
{
    char res[125];
    int num, fdc, fds;


    mknod(SERVER_FIFO, S_IFIFO | 0666, 0);
    
    
    printf("Waiting for server Connection...\n");
    
    fds = open(SERVER_FIFO, O_WRONLY);

    if ((num = write(fds, CLIENT_REQUEST_DATA, strlen(CLIENT_REQUEST_DATA))) == -1)
        perror("write");
    else
        printf("Request Sent! \n");


    mknod(CLIENT_REQUEST_FIFO, S_IFIFO | 0666, 0);
    printf("Waiting for server Response...\n");
    fdc = open(CLIENT_REQUEST_FIFO, O_RDONLY);

    if ((num = read(fdc, res, 125)) == -1)
        perror("read");
    else
    {
        res[num] = '\0';
        printf("Server Response:\n\"%s\"\n",res);
    }


    return 0;
}