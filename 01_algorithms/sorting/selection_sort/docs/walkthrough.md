# Selection Sort Walkthrough

This walkthrough shows how the algorithm processes the array and how variables change per iteration.

## Initial array

`[64, 25, 12, 22, 11]`

---

## Iteration trace: successful search case

A successful search case is when the inner loop finds a smaller value and `smallest_index` changes.

| Iteration `i` | `smallest_index` start | `j` values scanned | Minimum found | Swap performed | Array after iteration |
|---|---|---|---|---|---|
| 0 | 0 | 1..4 | index 4 (`11`) | yes | `[11, 25, 12, 22, 64]` |
| 1 | 1 | 2..4 | index 2 (`12`) | yes | `[11, 12, 25, 22, 64]` |
| 2 | 2 | 3..4 | index 3 (`22`) | yes | `[11, 12, 22, 25, 64]` |
| 3 | 3 | 4 | index 3 (`25`) | no | `[11, 12, 22, 25, 64]` |

### Variable changes for iteration 0
- `i = 0`
- start `smallest_index = 0`
- compare `array[1]` with `array[0]` → 25 vs 64 → update `smallest_index = 1`
- compare `array[2]` with `array[1]` → 12 vs 25 → update `smallest_index = 2`
- compare `array[3]` with `array[2]` → 22 vs 12 → no change
- compare `array[4]` with `array[2]` → 11 vs 12 → update `smallest_index = 4`
- swap `array[0]` and `array[4]`

---

## Iteration trace: unsuccessful search case

An unsuccessful search case is when the current element is already the smallest and no swap occurs.

| Iteration `i` | `smallest_index` start | `j` values scanned | Minimum found | Swap performed | Array after iteration |
|---|---|---|---|---|---|
| 3 | 3 | 4 | index 3 (`25`) | no | `[11, 12, 22, 25, 64]` |

### Variable changes for iteration 3
- `i = 3`
- start `smallest_index = 3`
- compare `array[4]` with `array[3]` → 64 vs 25 → no update
- `smallest_index` remains 3
- no swap executed

---

## Summary of the trace

- Each outer loop iteration aims to place the correct smallest remaining value at index `i`
- The `smallest_index` variable is updated only when a strictly smaller array element appears
- The final sorted result is `[11, 12, 22, 25, 64]`
