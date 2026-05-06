# Selection Sort for Advanced Learners

This file focuses on selection sort’s complexity, correctness, and systems-level considerations.

## Time complexity

Selection sort always performs the same number of comparisons regardless of input order.

- Outer loop runs `size - 1` times
- Inner loop scans the remaining unsorted items
- Total comparisons: `(n-1) + (n-2) + ... + 1 = n(n-1)/2`
- Resulting time complexity: O(n²)

## Space complexity

Selection sort is in-place:

- Uses only a constant number of extra variables:
  - `temporary_variable`
  - `smallest_index`
  - loop counters `i`, `j`, `k`
- No additional arrays are allocated
- Space complexity: O(1)

## Edge cases and correctness

- Already sorted input:
  - `smallest_index` remains equal to `i`
  - No swap occurs
  - The algorithm still validates each position
- Reverse-sorted input:
  - Each pass finds a new minimum and performs a swap
- Single-element or empty array:
  - Outer loop does not execute
  - The array remains unchanged
- Correctness reasoning:
  - After each outer loop iteration, the prefix up to `i` is the smallest set of values in sorted order
  - The remaining elements still contain all larger values
  - This invariant guarantees the full array is sorted at completion

## Trade-offs and limitations

- Simple and easy to implement
- Performs poorly on large arrays due to O(n²) comparisons
- Not stable if equal values exist and swap changes order
- Best use case: small arrays or educational examples

## Variants

- Iterative form:
  - The provided code is the standard iterative selection sort
- Recursive form:
  - Selection sort can be implemented recursively by selecting the minimum and recursing on the remainder, but this adds recursion overhead
- Comparison to other sorts:
  - Better than bubble sort only in the sense of predictable behavior
  - Not competitive with O(n log n) sorts for larger datasets

## Low-level considerations

- Integer overflow:
  - The implementation only moves integer values without arithmetic operations, so overflow is not a concern here
- Memory behavior:
  - The array is modified in place, which is cache-friendly for small arrays
  - Frequent swaps may still damage locality if positions are far apart
- CPU behavior:
  - The nested loops create predictable branch patterns
  - The inner comparison `if (array[j] < array[smallest_index])` is the dominant operation
- Compilation:
  - Use `-O2` or `-O3` when performance matters, though selection sort remains quadratic
