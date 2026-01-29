# Contact Manager (C)

A small **Contact Manager** written in **C** to practice core programming fundamentals such as:

- structs and strings
- arrays and dynamic memory
- file input/output
- modular code organization

This project is part of my broader **C language learning repository** and focuses on clean, readable code and fundamental computer science concepts.

---

## Features

- Add new contacts
- List all contacts
- Search contacts
- Edit or remove contacts
- Persist data using files (save/load)

*(Adjust this list to match the features currently implemented in your code.)*

---

## Project Structure (suggested)

contactManager/
├── include/
├── src/
├── Makefile
└── README.md

---

## Build & Run

### Option A — Using Makefile (recommended)

make
./contact_manager

### Option B — Compile manually

gcc -Wall -Wextra -Werror src/*.c -o contact_manager
./contact_manager

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
