#include <stdio.h>
#include "selection_sort.h"

int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
    selectionSort(array,size);

    printf("Sorted array:\n");
    for(int i=0;i<size;i++){
        printf("%d \n",array[i]);
    }
    printf("\n");
    return 0;
}
