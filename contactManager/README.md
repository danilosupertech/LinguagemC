# Contact Manager (C)

**Gerenciador de Contatos simples em C**  
Aplicativo de console para adicionar, listar, editar e excluir contatos, utilizando arquivo binário para armazenamento.

---

## 🛠️ Como compilar / How to compile

No Linux/macOS/WSL:
```bash
gcc main.c contact_manager.c -o contact_manager


**Gerenciador de Contatos simples em C**  
Aplicativo de console para adicionar, listar, editar e excluir contatos, utilizando arquivo binário para armazenamento.

---

## 🛠️ Como compilar / How to compile

No Linux/macOS/WSL:
```bash
gcc main.c contact_manager.c -o contact_manager

gcc main.c contact_manager.c -o contact_manager.exe


===== Gerenciador de Contatos =====
1. Listar todos os contatos
2. Adicionar contato
3. Editar contato
4. Excluir contato
0. Sair
Escolha uma opção:

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
TARGET = contact_manager
SRC = main.c contact_manager.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c contact_manager.h
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(TARGET) contacts.db

contact_manager/
├── main.c               # Interface CLI e menu
├── contact_manager.h    # Declarações da API
├── contact_manager.c    # Implementação do módulo
├── contacts.db          # Arquivo binário gerado (não versionar)
└── Makefile             # Opcional (facilita build/clean)

