#include "selection_sort.h"
#include <stdio.h>

void selectionSort(int array[],int size){
    int temporary_variable,smallest_index;
    for(int i=0;i<size-1;i++){
        smallest_index = i;
        for(int j=i+1;j<size;j++){
            if(array[j]< array[smallest_index]){
                smallest_index = j;
            }
        }
        if(smallest_index != i){
            temporary_variable = array[i];
            array[i] = array[smallest_index];
            array[smallest_index] = temporary_variable;
        }
        printf("After iteration %d: ", i);
        for (int k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
