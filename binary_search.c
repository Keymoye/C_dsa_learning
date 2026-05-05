#include "binary_search.h"

int binarySearch(int array[],int size,int number){
    int lowest=0;
    int highest=size - 1;
    int mid;

    while(lowest<=highest){
        mid=(lowest+highest) / 2;
        if(number==array[mid]){
            return mid;
        }else if(number<array[mid]){
            highest=mid - 1;
        }else {
            lowest=mid + 1;
        }
    }
    return -1;
}
