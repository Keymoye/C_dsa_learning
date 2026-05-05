# 🧾 Binary Search: Pseudocode

**Language-independent algorithm definition**

---

## High-Level Pseudocode

```
ALGORITHM BinarySearch(array, size, target)
    
    INPUT:
        array   : sorted array of integers
        size    : number of elements
        target  : value to find
    
    OUTPUT:
        index   : position of target (0 to size-1)
        -1      : if target not found
    
    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    
    lowest ← 0
    highest ← size - 1
    
    WHILE lowest ≤ highest DO
        mid ← (lowest + highest) ÷ 2
        
        IF array[mid] = target THEN
            RETURN mid
        
        ELSE IF target < array[mid] THEN
            highest ← mid - 1
        
        ELSE
            lowest ← mid + 1
        
        END IF
    
    END WHILE
    
    RETURN -1

END ALGORITHM
```

---

## Detailed Pseudocode with Comments

```
ALGORITHM BinarySearch(array, size, target)

    // Initialize search boundaries
    lowest ← 0              // Start at beginning
    highest ← size - 1      // Start at end (0-indexed)
    
    // Continue while search space is valid
    WHILE lowest ≤ highest DO
        
        // Find middle of current range
        mid ← ⌊(lowest + highest) ÷ 2⌋  // Integer division
        
        // Check if middle element matches
        IF array[mid] = target THEN
            RETURN mid      // Found! Return immediately
        
        // Decide which half to search next
        ELSE IF target < array[mid] THEN
            highest ← mid - 1   // Target in left half
            // Continue loop with left half
        
        ELSE                    // target > array[mid]
            lowest ← mid + 1    // Target in right half
            // Continue loop with right half
        
        END IF
        
        // Loop continues with updated boundaries
    
    END WHILE
    
    // If we reach here, target was never found
    RETURN -1

END ALGORITHM
```

---

## Decision Tree Format

```
START
  │
  ├─ lowest ← 0, highest ← size-1
  │
  ├─ WHILE lowest ≤ highest
  │    │
  │    ├─ mid ← (lowest + highest) / 2
  │    │
  │    ├─ IF array[mid] = target
  │    │    └─ RETURN mid  ✓ FOUND
  │    │
  │    ├─ ELSE IF target < array[mid]
  │    │    └─ highest ← mid - 1
  │    │       └─ LOOP (search left)
  │    │
  │    └─ ELSE
  │         └─ lowest ← mid + 1
  │            └─ LOOP (search right)
  │
  ├─ RETURN -1  ✗ NOT FOUND

END
```

---

## State Variables

| Variable | Type | Range | Purpose |
|----------|------|-------|---------|
| lowest | integer | 0 to size-1 | Left boundary of search |
| highest | integer | 0 to size-1 | Right boundary of search |
| mid | integer | 0 to size-1 | Middle point (calculated) |

---

## Loop Invariant

**True at every iteration start:**

> If `target` exists in the input array, then `target` is in `array[lowest..highest]`

**Proof:**
1. **Initialization:** Initially, `lowest=0, highest=size-1`, so all elements are in range ✓
2. **Maintenance:** Each iteration narrows range but preserves target if it exists
3. **Termination:** `lowest > highest` means all elements exhausted → target not found ✓

---

## Complexity

| Metric | Value | Reasoning |
|--------|-------|-----------|
| **Time** | O(log n) | Halve search space each iteration |
| **Space** | O(1) | Constant variables, no data structures |
| **Best Case** | Θ(1) | Target at mid (first check) |
| **Worst Case** | Θ(log n) | Target not found or boundary |

---

## Preconditions (Must be true)

1. `array` is sorted in ascending order
2. `size ≥ 0`
3. `array` has exactly `size` elements

**If violated:** Algorithm produces undefined results.

---

## Postconditions (Guaranteed after execution)

1. If result ≠ -1: `array[result] = target`
2. If result = -1: `target` not in array
3. Either condition is true

---

## Comparison with Linear Search

```
LINEAR SEARCH:
    FOR i FROM 0 TO size-1
        IF array[i] = target
            RETURN i
    RETURN -1
    
Time: O(n)
Requires: Nothing (array can be unsorted)

BINARY SEARCH:
    (as defined above)
    
Time: O(log n)
Requires: Array must be sorted
```

---

## Using This Pseudocode

To implement in any language:

1. Translate names: `lowest` might become `low`, `highest` becomes `high`
2. Handle language-specific syntax (loops, conditionals)
3. Implement integer division appropriately
4. Return -1 or equivalent "not found" value

**Language-independent core:** The logic remains constant.
