# Memory Allocation (C)

This project contains **practical exercises and examples** focused on **dynamic memory management in C**.

The goal is to understand how memory is allocated, resized, and released at runtime using standard C functions.

---

## 📌 Topics Covered

- `malloc`
- `calloc`
- `realloc`
- `free`
- Pointer arithmetic
- Memory leaks and common pitfalls
- Safe allocation patterns

---

## 🎯 Purpose

Dynamic memory management is one of the most critical aspects of C programming.

This project was created to:
- Practice correct memory allocation and deallocation
- Understand ownership and lifetime of memory blocks
- Avoid common errors such as leaks, double free, and invalid access

---

## 📂 Project Structure (example)

```
memory-allocation/
├── examples/        # Small focused examples
├── exercises/       # Practice exercises
├── src/             # Source files (.c)
├── include/         # Header files (.h)
└── README.md
```

*(The actual structure may vary depending on the exercise.)*

---

## 🧪 Testing

Run the test suite to verify compilation and memory management:

```bash
bash test.sh
```

**What the tests cover:**
- ✓ Source files (Malloc_Calloc.c, TesteMalloc.c, TesteCalloc.c) exist
- ✓ Compilation with strict GCC flags (-Wall -Wextra -std=c99)
- ✓ malloc/calloc/free usage verification
- ✓ Program execution and functionality
- ✓ Memory leak detection (valgrind if available)
- ✓ Code quality and warnings

**Test output example:**
```
╔════════════════════════════════════════════════╗
║   Memory Allocation - Test Suite              ║
╚════════════════════════════════════════════════╝

Testing: Files exist... ✓ PASSED
Testing: Compilation... ✓ PASSED
Testing: malloc/calloc detected... ✓ PASSED
Testing: Memory checks (valgrind)... ✓ PASSED
Testing: Code quality... ✓ PASSED

╔════════════════════════════════════════════════╗
║         TEST RESULTS SUMMARY                  ║
╠════════════════════════════════════════════════╣
║ Tests Passed: 5 ✓
║ Tests Failed:  0
╚════════════════════════════════════════════════╝
```

---

## 🛠️ Build & Run

### Option 1: Using Test Script (recommended)

```bash
bash test.sh
```

### Option 2: Compile with gcc

```bash
gcc -Wall -Wextra -std=c99 *.c -o memory_allocation
./memory_allocation
```

If files are split into folders:

```bash
gcc -Wall -Wextra -std=c99 src/*.c -o memory_allocation
./memory_allocation
```

---

## 🧪 What You Will Find Here

- Examples showing how `malloc` and `free` work
- Reallocation scenarios using `realloc`
- Exercises highlighting incorrect usage and how to fix it
- Small programs to observe memory behavior

---

## ⚠️ Notes

- All code is written for learning and experimentation purposes.
- No external libraries are used beyond the C standard library.
- This project focuses on **understanding**, not optimization.

---

## 🚀 Future Improvements

- Add examples with structs and dynamic arrays
- Introduce Valgrind usage examples
- Add documentation explaining memory diagrams
