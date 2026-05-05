#include <stdio.h>
#include "binary_search.h"

int main(){
    int array[]= {1,3,5,7,9};
    int size= sizeof(array)/ sizeof(array[0]);
    int number,result;

    printf("Enter the number to be searched:\n");
    scanf("%d",&number);

    result = binarySearch(array,size,number);

    if(result != -1){
        printf("Found:%d at index:%d\n",number,result);
    }else{
        printf("Not Found\n");
    }
    return 0;

}
