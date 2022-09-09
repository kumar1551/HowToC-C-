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


void read_file(FILE *ptr, char *result){
    char contents[50];
    while (fgets(contents, 50, ptr) != NULL) {
        strcat(result, contents);
    }

}

int main(void)
{

    FILE * file_ptr;
    char res[125] = "", req[50];
    int num, fdc, fds;


    mknod(REQUEST_FIFO, S_IFIFO | 0666, 0);
    
    printf("Waiting for client request...\n");


    fdc = open(REQUEST_FIFO, O_RDONLY);


    if ((num = read(fdc, req, 50)) == -1)
        perror("read");
    else
    {
        req[num] = '\0';
        printf("client requested file : \"%s\"\n",req);
    }

    file_ptr = fopen(req, "r");

    if (!file_ptr){
        printf("File can't be opened \n");
        exit(0);
    }else{
        read_file(file_ptr, res);
    }

    mknod(RESPONSE_FIFO, S_IFIFO | 0666, 0);
    printf("Server Responding....\n");
    fds = open(RESPONSE_FIFO, O_WRONLY);



    if ((num = write(fds, res, strlen(res))) == -1)
        perror("write");
    else
        printf("Response :\n\"%s\"\n", res);

    return 0;
}