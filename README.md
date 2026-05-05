# 🔍 Binary Search in C

A clean, efficient implementation of the Binary Search algorithm in C, designed for learning and production use.

| Aspect | Details |
|--------|---------|
| **Algorithm** | Binary Search |
| **Language** | C |
| **Time Complexity** | O(log n) |
| **Space Complexity** | O(1) |
| **Prerequisite** | Array must be sorted |
| **Return** | Index if found, `-1` if not |

---

## 🏃 Quick Start

### Compile
```bash
gcc -o binary_search binary_search.c main.c
```

### Run
```bash
./binary_search                    # Linux/macOS
binary_search.exe                  # Windows
```

### Example
```
Enter the number to be searched:
7
Found:7 at index:3
```

---

## 📁 Project Structure

```
binary_search/
├── binary_search.h       # Function declaration
├── binary_search.c       # Algorithm implementation
├── main.c                # Driver program
└── docs/                 # Documentation (multiple levels)
    ├── 01_beginner.md    # For beginners
    ├── 02_intermediate.md # For C & DSA learners
    ├── 03_advanced.md    # For experienced programmers
    ├── walkthrough.md    # Step-by-step execution
    └── pseudocode.md     # Language-neutral pseudocode
```

---

## 📚 Documentation Levels

Choose your level:

- **🟢 [Beginner](docs/01_beginner.md)** — No programming background? Start here.
- **🟡 [Intermediate](docs/02_intermediate.md)** — Learning C and algorithms? This is for you.
- **🔴 [Advanced](docs/03_advanced.md)** — Experienced programmer? Dive into trade-offs and optimization.
- **📊 [Walkthrough](docs/walkthrough.md)** — See the algorithm execute step-by-step.
- **🧾 [Pseudocode](docs/pseudocode.md)** — Language-independent algorithm design.

---

## 💡 Quick Insight

Binary Search reduces searching from **O(n) to O(log n)** by repeatedly halving the search space. For 1 million elements, it needs only ~20 comparisons instead of 500,000.

**Requirement:** Your array must be sorted.

---

## ✨ Key Features

- ✓ Clean, modular C implementation
- ✓ Multi-level documentation (beginner → advanced)
- ✓ Step-by-step walkthroughs
- ✓ Production-ready code
- ✓ O(1) space complexity

---

## 🚀 Next Steps

1. Read documentation for your level
2. Study the walkthrough to understand execution
3. Compile and test with provided examples
4. Explore edge cases in advanced docs

Happy learning! 📖
