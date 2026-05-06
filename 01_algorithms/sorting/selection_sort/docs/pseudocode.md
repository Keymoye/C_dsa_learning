# Selection Sort Pseudocode

```
function selectionSort(list):
    n = length of list
    for current from 0 to n - 2:
        minIndex = current
        for candidate from current + 1 to n - 1:
            if list[candidate] < list[minIndex]:
                minIndex = candidate
        if minIndex is not current:
            swap list[current] and list[minIndex]
```

- `current` marks the first position in the unsorted portion
- `minIndex` tracks the smallest element found
- The inner loop searches for the smallest remaining item
- A swap happens only when a smaller item is found
