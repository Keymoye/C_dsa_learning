# 🟡 Binary Search: Intermediate Guide

**Target Audience:** Learning C and DSA | Comfortable with basic programming

---

## 🎯 Algorithm Overview

Binary Search finds a target value in a **sorted array** by:
1. Starting with the entire array
2. Looking at the middle element
3. Eliminating half the search space based on comparison
4. Repeating until found or search space exhausted

**Time:** O(log n) | **Space:** O(1)

---

## 🔄 How It Works (Step-by-Step)

1. Set `lowest = 0` (left boundary)
2. Set `highest = size - 1` (right boundary)
3. Loop while `lowest <= highest`:
   - Calculate `mid = (lowest + highest) / 2`
   - If `array[mid] == target`: **Found!** Return index
   - If `target < array[mid]`: Search left half (`highest = mid - 1`)
   - If `target > array[mid]`: Search right half (`lowest = mid + 1`)
4. If loop ends: **Not found!** Return -1

---

## 💻 Your Code Explained

### Header: `binary_search.h`

```c
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int binarySearch(int array[], int size, int number);

#endif
```

**What it does:**
- `#ifndef` / `#define` / `#endif` = Include guards (prevents duplicate declarations)
- Declares the function signature so other files know it exists

**Why separate?**
- Interface (.h) is what users see
- Implementation (.c) is hidden
- This separation enables modularity and reusability

---

### Implementation: `binary_search.c`

```c
#include "binary_search.h"

int binarySearch(int array[], int size, int number){
    int lowest=0;              // Left boundary
    int highest=size - 1;      // Right boundary (last valid index)
    int mid;                   // Middle index (calculated each iteration)

    while(lowest<=highest){
        mid=(lowest+highest) / 2;
        
        if(number==array[mid]){
            return mid;        // Found target at index mid
            
        }else if(number<array[mid]){
            highest=mid - 1;   // Target is left of mid, search left half
            
        }else {
            lowest=mid + 1;    // Target is right of mid, search right half
        }
    }
    return -1;  // Loop ended, target not found
}
```

---

### Variable Breakdown

| Variable | Type | Purpose | Example |
|----------|------|---------|---------|
| `array[]` | int* | Sorted array to search | `[1, 3, 5, 7, 9]` |
| `size` | int | Number of elements | `5` |
| `number` | int | Target value | `7` |
| `lowest` | int | Left boundary | Starts at `0` |
| `highest` | int | Right boundary | Starts at `4` (size-1) |
| `mid` | int | Middle index | Calculated as `(lowest+highest)/2` |

---

### The Loop: `while(lowest<=highest)`

**Why `<=` instead of `<`?**

The condition allows checking the final element when `lowest == highest`:

```c
Array: [5, 10]
If lowest=0, highest=1

With <:    0 < 1 → TRUE, check array[0]
           1 < 1 → FALSE, skip array[1] ✗ (MISS!)

With <=:   0 <= 1 → TRUE, check array[0]
           1 <= 1 → TRUE, check array[1] ✓ (CHECK!)
```

---

### Mid Calculation: `mid = (lowest + highest) / 2`

**Formula:** Integer division of the average

```c
Example 1: (0 + 4) / 2 = 2      // Exact middle
Example 2: (1 + 4) / 2 = 2      // Rounds down (5/2 = 2)
Example 3: (3 + 4) / 2 = 3      // Rounds down (7/2 = 3)
```

**Why this works:** In C, `/` is integer division (truncates down).

**Why middle?** Maximizes information: tells us which half to search next.

---

### Decision Logic

Three outcomes at each iteration:

```c
if(number==array[mid]){
    return mid;              // ✓ Found! Return immediately
    
}else if(number<array[mid]){
    highest=mid - 1;         // Left half (exclude mid, already checked)
    
}else {
    lowest=mid + 1;          // Right half (exclude mid, already checked)
}
```

**Important:** We use `mid - 1` and `mid + 1` (not `mid`) because we already checked `array[mid]`.

---

### Return Values

```c
return mid;   // Success: index of found element (0 to size-1)
return -1;    // Failure: element not in array
```

**Why -1 for "not found"?**
- `-1` is never a valid array index
- `0` IS a valid index, so it can't mean "not found"
- Convention: `-1` signals "invalid/not found"

---

### Driver Program: `main.c`

```c
#include <stdio.h>
#include "binary_search.h"

int main(){
    int array[]= {1,3,5,7,9};           // Pre-sorted array
    int size= sizeof(array)/ sizeof(array[0]);  // Calculate size: 5
    int number,result;

    printf("Enter the number to be searched:\n");
    scanf("%d",&number);                // Get user input

    result = binarySearch(array,size,number);  // Call function

    if(result != -1){
        printf("Found:%d at index:%d\n",number,result);   // Success
    }else{
        printf("Not Found\n");          // Failure
    }
    return 0;
}
```

**Critical Detail:** Array is SORTED `{1,3,5,7,9}`. Binary search fails on unsorted arrays.

---

## 🔄 Complexity Analysis

### Time Complexity: O(log n)

Each iteration **halves** the search space:

```
Iteration 1: Search space = n
Iteration 2: Search space = n/2
Iteration 3: Search space = n/4
...
Iteration k: Search space = n/2^k

When n/2^k = 1:  k = log₂(n)
```

**Examples:**

| Array Size | Max Comparisons |
|---|---|
| 10 | 4 |
| 100 | 7 |
| 1,000 | 10 |
| 1,000,000 | 20 |
| 1,000,000,000 | 30 |

---

### Space Complexity: O(1)

Only 3 integer variables regardless of input size:

```c
int lowest=0;        // 4 bytes
int highest=size-1;  // 4 bytes
int mid;             // 4 bytes
// Total: 12 bytes (constant)
```

This is **space-efficient**: grows with problem, not data size.

---

## ⚠️ Important Preconditions

**MUST be true for Binary Search to work:**

1. **Array is sorted** — Only way to make intelligent decisions
2. **Enough space** — Need at least one element
3. **Distinct values OK** — Works with duplicates (may find any occurrence)

---

## ✅ Edge Cases to Consider

### Case 1: Target at First Position
```
Array: [5, 10, 15]
Target: 5
Result: Index 0 ✓
```

### Case 2: Target at Last Position
```
Array: [5, 10, 15]
Target: 15
Result: Index 2 ✓
```

### Case 3: Single Element
```
Array: [7]
Target: 7
Result: Index 0 ✓

Array: [7]
Target: 5
Result: -1 ✓
```

### Case 4: Element Not Found
```
Array: [1, 3, 5, 7, 9]
Target: 6
Result: -1 ✓
```

---

## 🆚 Compared to Linear Search

| Aspect | Binary | Linear |
|--------|--------|--------|
| **Sorted Required** | ✓ Yes | ✗ No |
| **Time** | O(log n) | O(n) |
| **Worst Case (1M items)** | ~20 ops | ~500k ops |
| **Simplicity** | Medium | Simple |

**When sorted exists:** Binary is 25,000× faster.

---

## 🚀 Next Steps

- See step-by-step execution: **[Walkthrough](walkthrough.md)**
- Explore advanced topics: **[Advanced Guide](03_advanced.md)**
- View clean pseudocode: **[Pseudocode](pseudocode.md)**
