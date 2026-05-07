# Execution Walkthrough: Recursive Factorial

## Successful Case: factorial(4)

**Input:** 4
**Expected Output:** 24

### Step-by-Step Execution

| Step | Function Call | Current n | Action | Return Value | Stack Depth |
|------|---------------|-----------|--------|--------------|-------------|
| 1 | factorial(4) | 4 | n > 1, call factorial(3) | - | 1 |
| 2 | factorial(3) | 3 | n > 1, call factorial(2) | - | 2 |
| 3 | factorial(2) | 2 | n > 1, call factorial(1) | - | 3 |
| 4 | factorial(1) | 1 | Base case: return 1 | 1 | 3 |
| 5 | factorial(2) | 2 | Return 2 × 1 = 2 | 2 | 2 |
| 6 | factorial(3) | 3 | Return 3 × 2 = 6 | 6 | 1 |
| 7 | factorial(4) | 4 | Return 4 × 6 = 24 | 24 | 0 |

**Final Result:** 24

## Successful Case: factorial(0)

**Input:** 0
**Expected Output:** 1

### Step-by-Step Execution

| Step | Function Call | Current n | Action | Return Value | Stack Depth |
|------|---------------|-----------|--------|--------------|-------------|
| 1 | factorial(0) | 0 | Base case: return 1 | 1 | 0 |

**Final Result:** 1

## Unsuccessful Case: factorial(-1)

**Input:** -1
**Expected Output:** Invalid input message

### Step-by-Step Execution

| Step | Function Call | Current n | Action | Return Value | Stack Depth |
|------|---------------|-----------|--------|--------------|-------------|
| 1 | factorial(-1) | -1 | n < 0, return 0 | 0 | 0 |

**Main function check:** result == 0 && number != 0 → true
**Output:** "Invalid input or overflow occurred."

## Unsuccessful Case: factorial(25)

**Input:** 25
**Expected Output:** Invalid input message

### Step-by-Step Execution

| Step | Function Call | Current n | Action | Return Value | Stack Depth |
|------|---------------|-----------|--------|--------------|-------------|
| 1 | factorial(25) | 25 | n > 20, return 0 | 0 | 0 |

**Main function check:** result == 0 && number != 0 → true
**Output:** "Invalid input or overflow occurred."

## Variable State Tracking

For factorial(3), tracking key variables:

| Call Stack Level | n Value | Return Expression | Intermediate Result |
|------------------|---------|-------------------|---------------------|
| Level 2 | 1 | - | 1 |
| Level 1 | 2 | 2 × factorial(1) | 2 × 1 = 2 |
| Level 0 | 3 | 3 × factorial(2) | 3 × 2 = 6 |
