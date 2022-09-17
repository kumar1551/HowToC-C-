#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]){
    int pfds[2];

    pipe(pfds);

    if (!fork()) {
        // close(1);       /* close normal stdout */
        dup2(pfds[1], 1);
        // dup(pfds[1]);   /* make stdout same as pfds[1] */
        close(pfds[0]); /* we don't need this */
        execlp(argv[1], argv[1], argv[2], NULL);
    }
    else {
        // close(0);       /* close normal stdin */
        dup2(pfds[0], 0);
        // dup(pfds[0]);   /* make stdin same as pfds[0] */
        close(pfds[1]); /* we don't need this */
        execlp(argv[3], argv[3], NULL);
    }
    return 0;
}

