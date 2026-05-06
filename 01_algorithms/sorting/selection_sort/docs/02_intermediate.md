# Selection Sort for Intermediate Learners

This document explains the C implementation of selection sort and connects the algorithm to the code structure in this project.

## How the algorithm works

The algorithm processes the array in passes. Each pass selects the smallest remaining element and places it at the front of the unsorted section.

## Code structure

### `main.c`
- Defines `array[] = {64, 25, 12, 22, 11}`
- Computes `size` using `sizeof(array) / sizeof(array[0])`
- Calls `selectionSort(array, size)`
- Prints the sorted result

### `selection_sort.c`
- Implements `void selectionSort(int array[], int size)`
- Uses three variables:
  - `temporary_variable` for swapping values
  - `smallest_index` to track the position of the current minimum
  - loop indices `i`, `j`, and `k`

## Detailed flow

1. Outer loop: `for(int i = 0; i < size - 1; i++)`
   - `i` marks the current position in the array where the next smallest value should go.
   - Each iteration fixes one element in its final sorted position.

2. Initialize `smallest_index = i`
   - Assume the current item is the smallest in the unsorted section.

3. Inner loop: `for(int j = i + 1; j < size; j++)`
   - Compare each later element `array[j]` with `array[smallest_index]`.
   - If `array[j] < array[smallest_index]`, update `smallest_index = j`.

4. After scanning, check `if (smallest_index != i)`
   - If a smaller item was found, swap:
     - `temporary_variable = array[i]`
     - `array[i] = array[smallest_index]`
     - `array[smallest_index] = temporary_variable`

5. Print the array state after each iteration
   - The code uses another loop `for (int k = 0; k < size; k++)` to show progress.

## Variables and control flow

- `i` controls the sorted boundary and moves from left to right.
- `j` scans the unsorted portion to find a smaller element.
- `smallest_index` holds the index of the smallest found so far.
- The `if` condition inside the inner loop updates `smallest_index` only when a smaller value is discovered.
- The swap executes only when the smallest found is not already at position `i`.

## Relationship between logic and implementation

- `selectionSort` follows the algorithm exactly: choose minimum, swap if needed.
- The nested loops mirror the two-step process: find minimum, then place it.
- The code prints intermediate array states, making the sorting process visible.

## Pseudocode overview

- Set current position to first element
- While current position is not the last
  - Find the smallest remaining element
  - Swap it into the current position
  - Move to the next position
