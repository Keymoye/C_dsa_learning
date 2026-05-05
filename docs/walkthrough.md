# 📊 Binary Search: Step-by-Step Walkthrough

**Real execution of the algorithm with variable tracking**

---

## Example 1: Finding Element (Target = 7)

**Setup:**
```
Array: [1, 3, 5, 7, 9]
Indices: 0  1  2  3  4
Target: 7
```

---

### Iteration 1

**Condition Check:**
```c
while(lowest<=highest)  // while(0 <= 4) → TRUE
```

**Calculate Mid:**
```c
mid = (0 + 4) / 2 = 2
```

**Comparison:**
```
array[mid] = array[2] = 5
Is 7 == 5? NO
Is 7 < 5? NO
else: 7 > 5 → YES
```

**Action:**
```c
lowest = mid + 1 = 3
```

**State After Iteration 1:**
| Variable | Value |
|----------|-------|
| lowest | 3 |
| highest | 4 |
| mid | 2 |

---

### Iteration 2

**Condition Check:**
```c
while(3 <= 4) → TRUE
```

**Calculate Mid:**
```c
mid = (3 + 4) / 2 = 3
```

**Comparison:**
```
array[mid] = array[3] = 7
Is 7 == 7? YES → MATCH FOUND!
```

**Action:**
```c
return 3
```

---

### Summary: Finding 7

| Iteration | lowest | highest | mid | array[mid] | Comparison | Action |
|-----------|--------|---------|-----|------------|------------|--------|
| 1 | 0 | 4 | 2 | 5 | 7 > 5 | lowest = 3 |
| 2 | 3 | 4 | 3 | 7 | 7 == 7 | **RETURN 3** |

**Result:** `binarySearch([1,3,5,7,9], 5, 7)` returns **3**

✓ **Success:** 7 found at index 3 after 2 comparisons

---

## Example 2: Element Not Found (Target = 6)

**Setup:**
```
Array: [1, 3, 5, 7, 9]
Target: 6 (not in array)
```

---

### Iteration 1

**Condition Check:**
```c
while(0 <= 4) → TRUE
```

**Calculate Mid:**
```c
mid = (0 + 4) / 2 = 2
```

**Comparison:**
```
array[2] = 5
Is 6 == 5? NO
Is 6 < 5? NO
else: 6 > 5 → YES
```

**Action:**
```c
lowest = 2 + 1 = 3
```

**State:**
| Variable | Value |
|----------|-------|
| lowest | 3 |
| highest | 4 |

---

### Iteration 2

**Condition Check:**
```c
while(3 <= 4) → TRUE
```

**Calculate Mid:**
```c
mid = (3 + 4) / 2 = 3
```

**Comparison:**
```
array[3] = 7
Is 6 == 7? NO
Is 6 < 7? YES
```

**Action:**
```c
highest = 3 - 1 = 2
```

**State:**
| Variable | Value |
|----------|-------|
| lowest | 3 |
| highest | 2 |

---

### Iteration 3 (Loop Exit)

**Condition Check:**
```c
while(3 <= 2) → FALSE
```

**Exit Loop:**
```c
return -1
```

---

### Summary: Target Not Found

| Iteration | lowest | highest | mid | array[mid] | Comparison | Action |
|-----------|--------|---------|-----|------------|------------|--------|
| 1 | 0 | 4 | 2 | 5 | 6 > 5 | lowest = 3 |
| 2 | 3 | 4 | 3 | 7 | 6 < 7 | highest = 2 |
| 3 | - | - | - | - | 3 > 2 (exit) | **RETURN -1** |

**Result:** `binarySearch([1,3,5,7,9], 5, 6)` returns **-1**

✓ **Correct:** 6 not in array, returned -1 after 2 comparisons

---

## Example 3: First Element (Target = 1)

**Setup:**
```
Array: [1, 3, 5, 7, 9]
Target: 1 (first element)
```

**Execution:**

| Iteration | lowest | highest | mid | array[mid] | Comparison | Action |
|-----------|--------|---------|-----|------------|------------|--------|
| 1 | 0 | 4 | 2 | 5 | 1 < 5 | highest = 1 |
| 2 | 0 | 1 | 0 | 1 | 1 == 1 | **RETURN 0** |

**Result:** Found at index 0 ✓

---

## Example 4: Last Element (Target = 9)

**Setup:**
```
Array: [1, 3, 5, 7, 9]
Target: 9 (last element)
```

**Execution:**

| Iteration | lowest | highest | mid | array[mid] | Comparison | Action |
|-----------|--------|---------|-----|------------|------------|--------|
| 1 | 0 | 4 | 2 | 5 | 9 > 5 | lowest = 3 |
| 2 | 3 | 4 | 3 | 7 | 9 > 7 | lowest = 4 |
| 3 | 4 | 4 | 4 | 9 | 9 == 9 | **RETURN 4** |

**Result:** Found at index 4 ✓

---

## Pattern Recognition

### Search Space Reduction

Each iteration divides remaining space roughly in half:

```
Start:     [1, 3, 5, 7, 9]           (5 elements)
After Iter 1:    [7, 9]   OR  [1, 3, 5]  (2-3 elements)
After Iter 2:       [7]   OR  [9]    (1 element)
After Iter 3:      Found!
```

### Maximum Iterations for Size n

```
Array Size | Max Iterations
5          | 3
10         | 4
100        | 7
1,000      | 10
1,000,000  | 20
```

This is ⌈log₂(n)⌉.

---

## Visualizing Variable Changes

### Variable Timeline: Finding 7

```
Time 0 (Initial):
    lowest=0, highest=4, mid=?

Time 1 (After Iter 1):
    lowest=3, highest=4, mid=2 (old)

Time 2 (After Iter 2):
    lowest=3, highest=4, mid=3 (old)
    RETURN 3 ← FOUND
```

### Variable Timeline: Target Not Found

```
Time 0 (Initial):
    lowest=0, highest=4, mid=?

Time 1 (After Iter 1):
    lowest=3, highest=4, mid=2 (old)

Time 2 (After Iter 2):
    lowest=3, highest=2, mid=3 (old)
    Condition: while(3 <= 2) → FALSE
    RETURN -1 ← NOT FOUND
```
