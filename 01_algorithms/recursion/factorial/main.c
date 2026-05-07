#include <stdio.h>
#include "factorial.h"

int main()
{
    int number;
    unsigned long long result;

    printf("Enter a Factorial number:\n");
    scanf("%d", &number);

    result = factorial(number);

    if (result == 0 && number != 0) {
        printf("Invalid input or overflow occurred.\n");
    } else {
        printf("The result is: %llu\n", result);
    }

    return 0;
}
