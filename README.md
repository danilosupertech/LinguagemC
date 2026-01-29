# C Language Lab - EstudoC

This repository is a collection of **C language practice projects and exercises** focused on building a strong foundation in low-level programming.

It contains multiple small programs and experiments developed while studying:
- pointers and memory
- data structures
- file handling
- modular C programs

## 📂 Repository Structure

Each folder represents an independent exercise or mini-project:

- **shopping-cart/** – Professional implementation of a shopping cart using linked lists
- **contactManager/** – Contact management system with file I/O
- **queue/** – Queue (FIFO) data structure implementation
- **pointers/** – Pointer basics and memory access exercises
- **memory-allocation/** – Dynamic memory allocation (malloc/calloc)
- **manipulate-files/** – File handling and text processing

Each directory contains:
- Source code files (.c)
- Header files (.h) where applicable
- **test.sh** – Comprehensive test suite for that project
- **README.md** – Documentation explaining the project

## 🧪 Testing All Projects

Each project has its own test suite. To test a specific project:

```bash
cd <project-directory>
bash test.sh
```

### Available Projects for Testing:

| Project | Command | Tests |
|---------|---------|-------|
| **shopping-cart** | `cd shopping-cart && bash test.sh` | 11+ comprehensive tests |
| **contactManager** | `cd contactManager && bash test.sh` | Compilation, memory, code quality |
| **queue** | `cd queue && bash test.sh` | Compilation, function detection, execution |
| **pointers** | `cd pointers && bash test.sh` | Multi-file compilation, memory checks |
| **memory-allocation** | `cd memory-allocation && bash test.sh` | malloc/calloc/free verification |
| **manipulate-files** | `cd manipulate-files && bash test.sh` | File I/O detection, compilation |

### Test Output Example:

Each test script provides:
- ✅ Colored output (GREEN = passed, RED = failed, YELLOW = warnings)
- 📊 Summary statistics (Tests Passed / Tests Failed)
- 🔍 Detailed checks for compilation, memory, and functionality
- ⏱️ Valgrind memory leak detection (when available)

## 🧠 Topics Covered

- Pointers and memory management
- Dynamic allocation (`malloc`, `realloc`, `free`)
- Structs and modular code
- Data structures (queues, linked lists, arrays)
- File I/O
- Command-line programs
- Safe C programming practices

## 🎯 Purpose

This repository serves as a **learning lab** for mastering C fundamentals and reinforcing concepts that are essential for systems programming and low-level software development.

## 🚀 Quick Start

```bash
# Test a specific project
cd shopping-cart
bash test.sh

# Or test all projects
for dir in shopping-cart contactManager queue pointers memory-allocation manipulate-files; do
    echo "Testing $dir..."
    cd $dir
    bash test.sh
    cd ..
done
```

## ⚠️ Notes

- All code is written for learning purposes.
- Projects are independent and may follow different styles depending on the learning phase.
- Test suites use strict GCC compilation flags: `-Wall -Wextra -std=c99 -pedantic`
- Memory testing with valgrind is optional but recommended

**Status:** 🚀 All projects now include comprehensive test suites and documentation
