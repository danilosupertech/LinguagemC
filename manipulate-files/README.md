# File Handling (C)

This folder contains exercises and mini-programs focused on **file input/output in C**.

The goal is to practice reading and writing files safely and correctly, using the C standard library.

---

## Topics Covered

- Opening and closing files (`fopen`, `fclose`)
- Reading files:
  - `fgets` (recommended for lines)
  - `fscanf` (formatted input)
  - `fread` (binary)
- Writing files:
  - `fprintf` (formatted output)
  - `fputs` / `fwrite`
- File modes: `r`, `w`, `a`, `rb`, `wb`
- Error handling:
  - checking `NULL` after `fopen`
  - using `perror` / `errno`
- Common pitfalls:
  - forgetting to close files
  - buffer overflows
  - incorrect format specifiers
  - not handling end-of-file correctly

---

## How to Build & Run

Because each exercise may be independent, compile a specific file like this:

```bash
gcc -Wall -Wextra -Werror <file>.c -o <program>
./<program>
```

Example:

```bash
gcc -Wall -Wextra -Werror read_file.c -o read_file
./read_file
```

---

## Suggested Folder Layout (optional improvement)

If you want to standardize this section later:

```
files/
├── src/
├── include/
├── samples/        # sample input files
├── Makefile
└── README.md
```

---

## Notes

- This code is written for learning and portfolio purposes.
- No external libraries are used beyond the C standard library.
- If your programs depend on input files, consider adding them under a `samples/` folder.

---

## Next Improvements (optional)

- Add sample input files + expected outputs
- Add a Makefile with `make`, `make run`, `make clean`
- Include a small program that copies a file (text/binary)
- Add basic argument parsing (read/write files via CLI)

### Quick tip: check errors properly
A safe pattern:

```c
FILE *fp = fopen("input.txt", "r");
if (!fp) {
    perror("fopen");
    return 1;
}
```

Remember to always `fclose(fp)` when done.
