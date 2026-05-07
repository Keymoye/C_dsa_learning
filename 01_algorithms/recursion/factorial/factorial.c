#include "factorial.h"

unsigned long long factorial(int number)
{
    // invalid input
    if (number < 0) {
        return 0;
    }

    // overflow guard (unsigned long long limit)
    if (number > 20) {
        return 0;
    }

    // base case
    if (number == 0 || number == 1) {
        return 1;
    }

    // recursive case
    return number * factorial(number - 1);
}
