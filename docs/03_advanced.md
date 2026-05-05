# 🔴 Binary Search: Advanced Topics

**Target Audience:** Experienced programmers | Interested in optimization and trade-offs

---

## 📊 Time Complexity: Deep Dive

### Why O(log n)?

**Proof by recurrence:**

Let T(n) = time to search n elements.

```
T(n) = 1 + T(n/2)    (one comparison + time for half-size problem)
     = 1 + 1 + T(n/4)
     = 1 + 1 + 1 + T(n/8)
     ...
     = log₂(n) × 1 + T(1)
     = log₂(n) + O(1)
     = O(log n)
```

**Therefore:** Maximum comparisons ≈ ⌈log₂(n)⌉

---

### Best, Average, Worst Cases

| Case | Probability | Comparisons | Reason |
|------|---|---|---|
| **Best** | Rare (~1/n) | 1 | Target at mid on first check |
| **Average** | Typical | log n / 2 | Random target location |
| **Worst** | Rare | log n | Target at boundary or missing |

**Practical insight:** All cases are logarithmic. Worst case ≈ best case (within constant factor).

---

## 💾 Space Complexity: O(1) Analysis

### Iterative Implementation (Your Code)

```c
int binarySearch(int array[], int size, int number){
    int lowest=0;              // 4 bytes
    int highest=size - 1;      // 4 bytes
    int mid;                   // 4 bytes
    
    while(lowest<=highest){    // Loop iterations: log₂(n), but no extra space
        // ...
    }
}
```

**Auxiliary space:** Fixed 12 bytes, regardless of n.

**Space complexity:** O(1)

### Recursive Implementation (Alternative)

```c
int binarySearchRec(int array[], int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (array[mid] == target) return mid;
    if (target < array[mid]) 
        return binarySearchRec(array, low, mid-1, target);  // Recursive call
    else
        return binarySearchRec(array, mid+1, high, target);  // Recursive call
}
```

**Call stack per recursion:** log₂(n) frames × frame size.

**Space complexity:** O(log n)

---

### Iterative vs Recursive Trade-offs

| Aspect | Iterative (Your Code) | Recursive |
|--------|------|---|
| **Space** | O(1) ✓ | O(log n) ✗ |
| **Speed** | No function call overhead ✓ | Function call overhead ✗ |
| **Stack Overflow Risk** | None ✓ | Possible on huge arrays ✗ |
| **Code Elegance** | Explicitly manages loop ✗ | Divide-and-conquer elegance ✓ |
| **Cache Locality** | Better ✓ | Slightly worse ✗ |

**Recommendation:** Iterative for production. Recursive for teaching.

---

## 🔢 Integer Overflow in Mid Calculation

### The Problem

```c
int mid = (lowest + highest) / 2;
```

On **32-bit systems**, `int` ranges: -2,147,483,648 to 2,147,483,647

**Overflow scenario:**
```c
int lowest = 2000000000;
int highest = 2100000000;
int sum = lowest + highest;  // 4,100,000,000 > MAX_INT
// Result: UNDEFINED BEHAVIOR (typically wraps to negative)
```

---

### Overflow-Safe Implementation

**Method 1: Avoid the sum (PREFERRED)**
```c
int mid = lowest + (highest - lowest) / 2;
```

**Why safe:**
- `(highest - lowest)` ≤ n (array size), usually small
- No overflow occurs

**Method 2: Use wider type**
```c
int mid = (int)((long)lowest + (long)highest) / 2;
```

**Why safe:**
- `long` has 64-bit range
- Explicit cast prevents surprises

---

### When It Matters

```
32-bit system, array size > 2 billion:
  Standard formula: DANGEROUS
  Overflow-safe formula: SAFE

64-bit system:
  Less critical (64-bit ints accommodate huge arrays)
  
Best practice:
  Always use overflow-safe version in production
```

---

## 🎯 Correctness: Why the Algorithm Works

### Invariant

After iteration k:
- If target exists, it's in range `[lowest, highest]`
- All elements outside this range are correctly eliminated

**Proof by loop invariant:**

**Initialization:** `lowest=0, highest=size-1` covers entire array ✓

**Maintenance:** Each iteration either:
1. Finds target → return immediately ✓
2. Eliminates left half (target > middle) → `lowest = mid+1` ✓
3. Eliminates right half (target < middle) → `highest = mid-1` ✓

**Termination:** Loop exits when `lowest > highest` → all possibilities exhausted → return -1 ✓

---

## 🔀 Edge Case Analysis

### Single Element Array

```c
Array: [7]
Initial: lowest=0, highest=0

Iteration 1: mid=0, compare array[0]
             If match: return 0
             If no match: either lowest/highest adjusts out of bounds
             
Iteration 2: while(lowest > highest) → FALSE → return -1
```

**Correctly handled:** ✓

---

### Empty Array

```c
Array: []
size = 0
Initial: lowest=0, highest=-1

Check: while(0 <= -1) → FALSE
Immediately return -1
```

**Correctly handled:** ✓

---

### Duplicates

```c
Array: [1, 3, 3, 3, 5]
Target: 3

Binary search finds THE FIRST (or any) occurrence of 3.
If you need all occurrences: 
  1. Find one occurrence
  2. Scan left until array[i] != 3
  3. Scan right until array[i] != 3
```

---

## 📈 Performance Characteristics

### Comparison with Alternatives

| Algorithm | Time | Space | Notes |
|-----------|------|-------|-------|
| **Binary Search** | O(log n) | O(1) | Requires sorted array |
| **Linear Search** | O(n) | O(1) | Works unsorted |
| **Hash Table** | O(1) avg | O(n) | Random access, extra memory |
| **Binary Search Tree** | O(log n) | O(n) | Dynamic insertions |

---

### Practical Scaling

For **1 billion elements**:

```
Binary Search:   ~30 comparisons
Linear Search:   ~500 million comparisons
Hash Table:      ~1 lookup (but uses 8+ bytes per element)
```

Binary Search wins on sorted static data with limited memory.

---

## 🚀 Advanced Applications

### 1. Range Queries

Find all elements in [a, b]:
```
binary_search(first ≥ a)  // O(log n)
binary_search(last ≤ b)   // O(log n)
Return range between indices
```

---

### 2. Version Control (git bisect)

Find first breaking commit in history:
```
Current: commit 500 (works)
Try 750: broken → bug before 750
Try 625: broken → bug before 625
Try 562: works → bug after 562
...
```

**Finds bad commit in O(log n) tests instead of O(n).**

---

### 3. Machine Learning: Hyperparameter Search

Find optimal learning rate:
```
Try rate = 0.5: high error
Try rate = 0.25: lower error
Try rate = 0.125: even lower
...
```

Binary search on hyperparameter space.

---

## 🎓 Why This Matters Beyond Code

Binary Search teaches:

1. **Divide-and-conquer:** Break problem recursively
2. **Exploit structure:** Use sorted property intelligently
3. **Logarithmic thinking:** Exponential reduction in problem size
4. **Loop invariants:** Formal reasoning about correctness
5. **Trade-offs:** Time vs space (iterative vs recursive)

These apply to:
- Sorting algorithms (merge sort, quicksort)
- Tree traversal (BST, AVL, B-trees)
- Database indexing
- System design
- Optimization

---

## 📚 Implementation Considerations for Production

1. **Verify preconditions:** Assert array is sorted
2. **Use overflow-safe mid:** `lowest + (highest - lowest) / 2`
3. **Handle empty arrays:** Explicit check before binary search
4. **Document assumptions:** Clear about expected input format
5. **Test edge cases:** First, last, not found, empty, duplicates
6. **Consider caching:** Repeated searches on same array may warrant preprocessing

---

## 🏁 Summary

Binary Search is elegant because:
- ✓ Simple to implement correctly
- ✓ Guaranteed logarithmic performance
- ✓ O(1) space overhead
- ✓ Foundation for advanced data structures
- ✓ Demonstrates powerful algorithmic thinking

Mastering it builds intuition for algorithm design and analysis.
