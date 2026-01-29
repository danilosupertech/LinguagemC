<<<<<<< HEAD
# Pointers (C)
=======
# 📍 Ponteiros em C - Exercícios e Aprendizado

> Projeto de estudo sobre **ponteiros**, **manipulação de memória** e **arrays dinâmicos** em linguagem C.

## 📚 Conceitos Estudados

### ✅ 1. "argv[] é um ponteiro de ponteiro"
👉 Correto com pequena revisão de nomenclatura:
>>>>>>> 5d343a0 (send modifications)

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

<<<<<<< HEAD
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
=======
c
Copy
Edit
char *str = *argv;
```

`str` e `*argv` agora apontam para a **mesma região de memória**, ou seja, para o início da string atual.

Você pode modificar `str` (fazer `str++`, etc.) sem alterar `argv`, porque você está só mudando o endereço contido em `str`.

🧠 **Analogia:** Dois marcadores apontando para o mesmo lugar em um mapa: um você move, o outro fica parado.

## ✅ Conclusão do Raciocínio

| Conceito | Correto? | Comentário |
|---|---|---|
| argv é ponteiro de ponteiro | ✅ | `char **argv` |
| argv não termina com \0 | ✅ | Termina com NULL |
| *argv é ponteiro para string que termina com \0 | ✅ | Strings em C são nulas-terminadas |
| char *str = *argv copia o ponteiro, não a string | ✅ | Ponteiros distintos, mesma memória |
| Pode iterar str até *str == '\0' | ✅ | Forma correta de percorrer string |

---

## 📁 Estrutura do Projeto

```
pointers/
├── main.c           # Exemplo 1: Uso básico de ponteiros
├── mainx.c          # Exemplo 2: Manipulação avançada
├── vetores.c        # Exemplo 3: Arrays e alocação dinâmica
├── funct.h          # Header com funções auxiliares
├── README.md        # Este arquivo
└── test.sh          # Suite de testes
```

## 🧪 Testing

Run the test suite to verify compilation and functionality:

```bash
bash test.sh
```

**What the tests cover:**
- ✓ Source files (main.c, mainx.c, vetores.c) exist
- ✓ Compilation with strict GCC flags (-Wall -Wextra -std=c99)
- ✓ Malloc/pointer usage detection
- ✓ Program execution and functionality
- ✓ Memory leak detection (valgrind if available)
- ✓ Code quality and warnings

**Test output example:**
```
╔════════════════════════════════════════════════╗
║      Pointers - Test Suite                    ║
╚════════════════════════════════════════════════╝

Testing: Files exist... ✓ PASSED
Testing: Compilation (main.c)... ✓ PASSED
Testing: Compilation (mainx.c)... ✓ PASSED
Testing: Compilation (vetores.c)... ✓ PASSED
Testing: Pointer usage detected... ✓ PASSED
Testing: Memory checks... ✓ PASSED

╔════════════════════════════════════════════════╗
║         TEST RESULTS SUMMARY                  ║
╠════════════════════════════════════════════════╣
║ Tests Passed: 6 ✓
║ Tests Failed:  0
╚════════════════════════════════════════════════╝
```

---

## 🚀 Build & Run

### Option 1: Using Test Script (recommended)

```bash
bash test.sh
```

### Option 2: Manual Compilation

```bash
# Compile individual files
gcc -Wall -Wextra -std=c99 main.c -o pointers_main
gcc -Wall -Wextra -std=c99 mainx.c -o pointers_mainx
gcc -Wall -Wextra -std=c99 vetores.c -o pointers_vetores

# Run
./pointers_main
./pointers_mainx
./pointers_vetores
```

---

## 💡 Key Learning Points

- **Diferença entre ponteiro e conteúdo**: `ptr` vs `*ptr`
- **Aritmética de ponteiros**: `ptr++`, `ptr + n`
- **Arrays e ponteiros**: `arr[i]` é equivalente a `*(arr + i)`
- **Alocação dinâmica**: `malloc()`, `free()`
- **Passagem por referência**: Modificar valores através de ponteiros
- **Strings dinâmicas**: Alocação e manipulação

---

## ⚠️ Boas Práticas

✅ Sempre verificar se `malloc` foi bem-sucedido  
✅ Liberar memória com `free()` após uso  
✅ Usar `-Wall -Wextra` para detectar problemas  
✅ Entender a diferença entre stack e heap  
✅ Cuidado com dereference de ponteiros nulos  

---

## 🔍 Tipos de Ponteiros Explorados

- **Ponteiros para int, char, float**
- **Ponteiros para estruturas**
- **Ponteiros para ponteiros** (double pointers)
- **Arrays de ponteiros**
- **Ponteiros para arrays**

---

## 📖 Recursos Recomendados

- The C Programming Language (Kernighan & Ritchie)
- Cprogramming.com - Pointers Tutorial
- GeeksforGeeks - Pointers in C

---

**Versão:** 1.0  
**Autor:** Danilo Côrtes Gonçalves  
**Status:** Aprendizado em Progresso 🚀
argv é ponteiro de ponteiro	✅	char **argv
argv não termina com \0	✅	Termina com NULL
*argv é ponteiro para string que termina com \0	✅	Strings em C são nulas-terminadas
char *str = *argv copia o ponteiro, não a string	✅	Ponteiros distintos, mesma memória
Pode iterar str até *str == '\0'	✅	Forma correta de percorrer string
>>>>>>> 5d343a0 (send modifications)
