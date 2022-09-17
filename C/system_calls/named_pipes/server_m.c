#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

#define REQUEST_FIFO "client_request"

#define RESPONSE_FIFO "server_response"

#define SERVER_FIFO "well_known_server_response"
#define CLIENT_1_REQUEST_FIFO "client_1_request"
#define CLIENT_2_REQUEST_FIFO "client_2_request"


int main(void)
{

    char req1[125] = "", req2[125] = "", client;
    int num, fds, fdc1, fdc2;


    mknod(SERVER_FIFO, S_IFIFO | 0666, 0);
    printf("Waiting for client request...\n");
    fds = open(SERVER_FIFO, O_RDONLY);

    mknod(CLIENT_1_REQUEST_FIFO, S_IFIFO | 0666, 0);
    fdc1 = open(CLIENT_1_REQUEST_FIFO, O_WRONLY);
    printf("Client 1 Connected....\n");

    if ((num = read(fds, req1, 125)) == -1)
        perror("read");
    else {
        req1[num] = '\0';
        printf("Request by Client 1: \"%s\"\n", req1);
        if ((num = write(fdc1, req1, strlen(req1))) == -1)
            perror("write");
        else
            printf("Response to Client 1 :\n\"%s\"\n", req1);

    }
    

    mknod(CLIENT_2_REQUEST_FIFO, S_IFIFO | 0666, 0);
    fdc2 = open(CLIENT_2_REQUEST_FIFO, O_WRONLY);
    printf("Client 2 Connected....\n");

    
    if ((num = read(fds, req2, 125)) == -1)
        perror("read");
    else {
        req2[num] = '\0';

        printf("Request by Client 2: \"%s\"\n", req2);

        if ((num = write(fdc2, req2, strlen(req2))) == -1)
            perror("write");
        else
            printf("Response to Client 2 :\n\"%s\"\n", req2);

    }
    

    return 0;
}