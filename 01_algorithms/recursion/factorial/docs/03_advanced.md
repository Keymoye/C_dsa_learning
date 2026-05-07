# Factorial Algorithm: Advanced Analysis

## Time Complexity

**O(n)** - Linear time complexity.

**Derivation:**
- Each recursive call reduces the input by 1
- For input n, there are exactly n recursive calls
- Each call performs constant-time operations (comparisons, multiplication)
- Total operations = O(n)

**Call Stack Depth:** Also O(n) - maximum n function calls on the stack simultaneously.

## Space Complexity

**O(n)** - Linear space complexity.

**Breakdown:**
- **Call Stack:** Each recursive call adds a stack frame (typically 8-16 bytes on modern systems)
- **Maximum Depth:** n stack frames for factorial(n)
- **No Additional Data Structures:** Only primitive variables used

**Practical Limits:** Stack overflow occurs around n=1000-10000 depending on system stack size.

## Edge Cases & Correctness

### Boundary Conditions
- **n = 0:** Correctly returns 1 (0! = 1 by convention)
- **n = 1:** Correctly returns 1 (1! = 1)
- **n = 20:** Maximum computable value without overflow
- **n = 21:** Returns 0 (overflow prevention)

### Error Handling
- **Negative inputs:** Returns 0 (mathematically undefined)
- **Large inputs:** Returns 0 (prevents undefined behavior from overflow)

### Correctness Proof
The algorithm correctly computes n! because:
- Base case handles the fundamental definition
- Each recursive step applies the factorial formula: n! = n × (n-1)!
- The recursion terminates at the base case
- All paths lead to correct computation or error indication

## Trade-offs & Limitations

### Recursive vs Iterative

**Recursive Advantages:**
- Elegant, mathematical clarity
- Mirrors the inductive definition of factorial
- Easy to understand and implement

**Recursive Disadvantages:**
- Stack space usage O(n)
- Risk of stack overflow for large n
- Function call overhead

**Iterative Alternative:**
```c
unsigned long long factorial_iterative(int n) {
    if (n < 0 || n > 20) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```
- O(n) time, O(1) space
- No stack overflow risk
- Better for large inputs within range

### Low-Level Considerations

**Integer Overflow:**
- `unsigned long long` max: 18,446,744,073,709,551,615
- 20! = 2,432,902,008,176,640,000 (fits)
- 21! = 51,090,942,171,709,440,000 (overflows)

**CPU Behavior:**
- Multiplication operations are fast on modern CPUs
- Recursive calls involve stack management overhead
- Branch prediction works well for the base case check

**Memory Alignment:**
- `unsigned long long` typically 8-byte aligned
- Stack frames may include padding for alignment

### Performance Characteristics

**Best Case:** n = 0 or 1 (immediate return)
**Worst Case:** n = 20 (maximum recursion depth)
**Average Case:** N/A (deterministic algorithm)

**Cache Behavior:** Excellent - no memory access patterns, pure computation.