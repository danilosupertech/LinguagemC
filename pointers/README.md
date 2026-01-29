# Pointers (C)

A small collection of **C pointer** exercises and mini-programs focused on mastering:

- Pointer basics (`&`, `*`)
- Pointer arithmetic
- Arrays vs pointers
- Strings as `char *`
- Functions with pointer parameters
- Basic memory concepts (stack vs heap)

> This folder is part of my broader **C learning repository** and contains practice code written to reinforce fundamentals.

---

## 📁 What you’ll find here

Typical files in this folder may include exercises such as:

- Swapping values using pointers
- Iterating arrays using pointer arithmetic
- Working with strings via pointers
- Passing pointers to functions to modify variables “in place”
- Using pointers for simple data structure manipulation (when applicable)

If you want this folder to be more “portfolio-friendly”, keep **one exercise per file** and give files descriptive names (e.g., `swap_with_pointers.c`, `iterate_array_ptr.c`, `string_length_ptr.c`).

---

## ✅ Build & Run

Most examples are single-file programs. Compile with `gcc`:

```bash
gcc -Wall -Wextra -Werror -o program file.c
./program
```

If you have multiple files:

```bash
gcc -Wall -Wextra -Werror -o app *.c
./app
```

---

## 🧠 Notes / Tips

- Prefer `size_t` for sizes and indexes when iterating arrays.
- When passing arrays to functions, remember they “decay” to pointers:
  - `int arr[]` in a function parameter becomes `int *arr`
- To modify a variable inside a function, pass its **address**:
  - `void set_value(int *x) { *x = 42; }`

---

## 🚀 Next Improvements (optional)

To make this folder shine for recruiters:

- Add a short comment header to each file explaining the goal
- Add sample input/output in comments or in this README
- Create a `Makefile` with targets like `make`, `make run`, `make clean`

---

## ⚠️ Disclaimer

This repository contains **original practice code**.  
It does **not** include official school/subject material.
