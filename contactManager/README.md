# Contact Manager in C

A simple **Contact Manager** written in **C** to practice core programming fundamentals such as:

- structs and strings
- arrays and dynamic memory
- file input/output
- modular code organization

This project is part of a broader **C language learning repository** and focuses on clean, readable code and fundamental computer science concepts.

---

## Features

- Add new contacts
- List all contacts
- Search contacts
- Edit or remove contacts
- Persist data using files (save/load)

---

## Project Structure

```
contactManager/
├── contact_manager.h    # Header with function declarations
├── contact_manager.c    # Implementation
├── main.c               # User interface
├── Makefile             # Build script
└── README.md            # This file
```

---

## 🧪 Testing

Run the test suite to verify compilation and functionality:

```bash
bash test.sh
```

**What the tests cover:**
- ✓ Source file existence and integrity
- ✓ Compilation with strict GCC flags (-Wall -Wextra -std=c99)
- ✓ Memory leak detection (valgrind)
- ✓ Function detection and availability
- ✓ Code quality checks

**Test output example:**
```
╔════════════════════════════════════════════════╗
║   Contact Manager - Test Suite                ║
╚════════════════════════════════════════════════╝

Testing: Files exist... ✓ PASSED
Testing: Compilation... ✓ PASSED
Testing: Memory checks (valgrind)... ✓ PASSED
Testing: Code quality... ✓ PASSED

╔════════════════════════════════════════════════╗
║         TEST RESULTS SUMMARY                  ║
╠════════════════════════════════════════════════╣
║ Tests Passed: 4 ✓
║ Tests Failed:  0
╚════════════════════════════════════════════════╝
```

---

## Build & Run

### Option A — Using Test Script (recommended)

```bash
bash test.sh
```

### Option B — Compile manually

```bash
gcc -Wall -Wextra -std=c99 main.c contact_manager.c -o contact_manager
./contact_manager
```

---

## Example Usage

1) Add contact
2) List contacts
3) Search contact
4) Remove contact
0) Exit

---

## Notes

- All code is written for learning and portfolio purposes.
- No external libraries are used beyond the C standard library.
- No official course subjects or evaluation materials are included.

---

## Future Improvements

- Improve input validation
- Better memory management and cleanup
- Separate logic into clearer modules
- Add persistence using structured formats (CSV / binary)
