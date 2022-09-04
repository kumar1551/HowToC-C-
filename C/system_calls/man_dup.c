#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_STR "bash -c \"man %s; exit; exec bash\""


int main(int argc, char const *argv[]){
    int pfds[2];
    char buffer[10];

    char cmd[50];

    pipe(pfds);

    if (fork() != 0) {


        close(pfds[0]);
        write(pfds[1], argv[1], sizeof(argv[1]));

    }
    else {

        close(pfds[1]);
        read(pfds[0], buffer, sizeof(buffer));

        sprintf(cmd, CMD_STR, buffer);

        printf("%s\n", cmd);

        execlp("gnome-terminal", "gnome-terminal", "--", "sh", "-c", cmd, NULL);
    }

    return 0;
}