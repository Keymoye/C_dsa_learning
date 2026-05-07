# Recursive Factorial

function factorial(n)
    if n < 0 or n > 20
        return 0  // error: invalid input or overflow risk
    
    if n equals 0 or n equals 1
        return 1  // base case: factorial of 0 and 1 is 1
    
    return n × factorial(n - 1)  // recursive case: n! = n × (n-1)!