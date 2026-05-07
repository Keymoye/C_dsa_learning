# Factorial Algorithm: Intermediate Guide

## How the Algorithm Works

The recursive factorial algorithm breaks down the factorial calculation into smaller, identical subproblems. It works by:

1. **Base Case**: When the input reaches 0 or 1, return 1 (since 0! = 1 and 1! = 1)
2. **Recursive Case**: For any number n > 1, return n multiplied by factorial(n-1)
3. **Invalid Input**: Return 0 for negative numbers or numbers that would cause overflow

## Code Breakdown

### Function Signature
```c
unsigned long long factorial(int number)
```
- Takes an `int` parameter (the number to compute factorial for)
- Returns `unsigned long long` to handle large results
- Uses `unsigned long long` because factorial values grow very quickly

### Input Validation
```c
if (number < 0) {
    return 0;
}
```
- Checks for negative numbers
- Factorial is only defined for non-negative integers
- Returns 0 as an error indicator

### Overflow Protection
```c
if (number > 20) {
    return 0;
}
```
- `unsigned long long` can hold values up to 20!
- 21! would exceed the maximum value (18,446,744,073,709,551,615)
- Returns 0 to prevent integer overflow

### Base Case
```c
if (number == 0 || number == 1) {
    return 1;
}
```
- Stops the recursion when number reaches 0 or 1
- Both 0! and 1! equal 1 by mathematical definition

### Recursive Case
```c
return number * factorial(number - 1);
```
- Multiplies current number by factorial of (number - 1)
- This creates the chain: n! = n × (n-1) × (n-2) × ... × 1

## Control Flow Example

For factorial(3):
1. Call factorial(3)
2. 3 > 1, so call factorial(2)
3. 2 > 1, so call factorial(1)
4. factorial(1) returns 1 (base case)
5. factorial(2) returns 2 × 1 = 2
6. factorial(3) returns 3 × 2 = 6

## Main Function Integration

The `main.c` file:
- Prompts user for input using `printf` and reads with `scanf`
- Calls the `factorial` function
- Checks if result is 0 (error) when input wasn't 0
- Prints the result or error message

## Pseudocode Overview

```
function factorial(n):
    if n < 0 or n > 20:
        return 0  // error
    if n == 0 or n == 1:
        return 1  // base case
    return n * factorial(n - 1)  // recursive case
```