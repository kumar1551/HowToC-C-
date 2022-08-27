#include<stdio.h>
#include<stdlib.h>

// functions prototypes
int * create_array(int len); 
int * scan_array(int *arr, int len);
int * print_array(int *arr, int len);
int * rotate_array(int *arr, int len, int d);


int main()
{
    int n, d, *arr;

    system("cls");

    printf("\nEnter array size: ");
    scanf("%d", &n);

    arr = create_array(n);
    arr = scan_array(arr, n); // input

    system("cls");

    printf("\nEnter no of elements to rotate: ");
    scanf("%d", &d);

    printf("\nOriginal array: ");
    print_array(arr, n);

    arr = rotate_array(arr, n, d);
    
    printf("\nRotated array: ");
    print_array(arr, n);

    free(arr);

    return 0;
}


// functions implementations
int * create_array(int len){
    return (int *) malloc(len * sizeof(int));
}

int * scan_array(int *arr, int len){
    int i;

    for(i=0; i<len; i++){
        printf("Enter element %d: ", i);
        scanf("%d", arr+i);
    }

    return arr;
}

int * print_array(int *arr, int len){
    int i;
    for(i=0; i<len-1; i++)
        printf("%d, ", arr[i]); // printing till second last element
    printf("%d", arr[i]); // printing last element

}

int * rotate_array(int *arr, int len, int d){
    int * temp = create_array(len), i;
    
    for (i=0; i<d; i++){
        temp[len-d+i] = arr[i];
    }
    for (i=d; i<len; i++){
        temp[i-d] = arr[i];
    }

    free(arr);
    arr = temp;
    return arr;
}
