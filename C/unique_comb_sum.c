#include<stdio.h>
#include<stdlib.h>

// function prototypes


int main(){

    int arr[] = {2, 4, 6, 8}, sum = 8;

    int i, s;

    int *temp = (int * ) malloc(sizeof(int));

    for (i=0; i<4; i++){
        s = sum;

        s = s - arr[i];

        if (s>0){

        }
        

        while(s >0){
            s = s - arr[i];

            if (s == 0)
                printf("%d ", arr[i]);

            // printf("s = %d, arr[i] = %d", s, arr[i]);

            if (s > 0){
                
            }
            else
                i++;
        }
        printf("\n");
        
    }


    return 0;
}


// function implementations
