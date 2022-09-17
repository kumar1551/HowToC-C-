#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int i=0, count=0;

void alarm_handler(int signal_number){

    printf("Alarm clock\n\n");

    if ( ++count == 4) signal(SIGALRM, SIG_DFL);

    alarm(2);
}

int main(){

    signal(SIGALRM, alarm_handler);
    alarm(2);

    while(1) {
        printf("Programming Running, time = %d seconds\n", ++i);
        sleep(1);
    }

    return 0;
}
