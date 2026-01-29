# C Language Lab - EstudoC

A comprehensive collection of **C language learning projects** designed to build a strong foundation in low-level programming, data structures, and systems development.

This repository contains multiple small programs and experiments covering:
- Pointers and memory management
- Data structures (linked lists, queues, arrays)
- File I/O and data persistence
- Modular C programming practices
- Safe memory allocation and management

## 📂 Project Structure

Each folder is a self-contained exercise or mini-project:

- **shopping-cart/** – Professional shopping cart system using linked lists
- **contactManager/** – Contact management system with file persistence
- **queue/** – FIFO queue data structure implementation
- **pointers/** – Pointer fundamentals and memory access exercises
- **memory-allocation/** – Dynamic memory allocation with malloc/calloc
- **manipulate-files/** – File I/O and text processing examples

Every project includes:
- Source code files (.c)
- Header files (.h) where applicable
- **test.sh** – Automated test suite with color-coded output
- **README.md** – Complete documentation with examples

## 🧪 Testing

Each project has a comprehensive test suite. Run tests for any project:

```bash
cd <project-directory>
bash test.sh
```

### Projects & Test Coverage:

| Project | Success Rate | Tests Included |
|---------|--------------|----------------|
| **shopping-cart** | 89.5% ✓ | Compilation, memory, documentation, functions |
| **contactManager** | 100% ✓ | Compilation, memory, code quality checks |
| **queue** | 100% ✓ | Compilation, function detection, execution |
| **pointers** | 75% | Multi-file compilation, memory analysis |
| **memory-allocation** | 88.2% ✓ | malloc/calloc/free verification, memory leaks |
| **manipulate-files** | 87.5% ✓ | File I/O detection, compilation checks |

### Test Features:

- ✅ Colored output (GREEN = pass, RED = fail, YELLOW = warning)
- 📊 Test summary with pass/fail counts
- 🔍 Static analysis and compilation checks
- 💾 Memory leak detection with valgrind (if available)
- ⚡ Timeout protection on execution tests

## 🧠 Learning Topics

- **Pointers & Memory:** Understanding pointers, dereferencing, pointer arithmetic
- **Dynamic Allocation:** malloc, calloc, realloc, proper memory cleanup
- **Data Structures:** Linked lists, queues, arrays, proper struct design
- **File I/O:** Reading, writing, and processing files in C
- **Modular Design:** Separating concerns, header files, code organization
- **Best Practices:** Error handling, input validation, safe C coding patterns

## 🎯 Repository Purpose

This is a **learning laboratory** for:
- Mastering C fundamentals and advanced concepts
- Building production-quality, well-documented code
- Understanding systems programming principles
- Practicing professional software development practices

## 🚀 Quick Start

Test a specific project:
```bash
cd shopping-cart
bash test.sh
```

Test all projects:
```bash
for dir in shopping-cart contactManager queue pointers memory-allocation manipulate-files; do
    echo "Testing $dir..."
    cd $dir
    bash test.sh
    cd ..
done
```

## 📖 Documentation

- **Main README:** You're reading it!
- **Project READMEs:** See each project folder for detailed documentation
- **TEST_RESULTS.md:** Comprehensive test execution report
- **In-Code Comments:** Doxygen-style documentation throughout

## ✨ Project Status

**Overall Quality:** ⭐⭐⭐⭐ (84.6% success rate)

All projects include:
- ✅ Automated test suites
- ✅ Complete documentation
- ✅ Professional code structure
- ✅ Memory safety checks
- ✅ Clear build instructions

## ⚙️ Build Requirements

- GCC compiler with C99 support
- Bash shell
- Optional: Valgrind for memory checking

## 📝 Notes

- All code is written for educational purposes
- Each project is independent and can be studied separately
- Test suites use strict compilation flags: `-Wall -Wextra -std=c99 -pedantic`
- Memory analysis with valgrind is optional but recommended
- See individual project READMEs for specific details

---

**Version:** 1.0  
**Last Updated:** January 29, 2026  
**Author:** Danilo Côrtes Gonçalves
