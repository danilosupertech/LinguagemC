# 🚀 Quick Start Guide - Shopping Cart

Um guia rápido para colocar o **Carrinho de Compras** em funcionamento em minutos!

---

## ⚡ Começar em 3 Passos

### 1️⃣ Compilar o Projeto

```bash
cd shopping-cart
make
```

**Resultado esperado:**
```
Compiling main.c...
Compiling shopping_cart.c...
Linking bin/shopping_cart...
✓ Build successful!
  Executable: bin/shopping_cart
```

### 2️⃣ Executar o Programa

```bash
make run
```

Ou diretamente:

```bash
./bin/shopping_cart
```

### 3️⃣ Usar o Menu

```
╔════════════════════════════════╗
║  SISTEMA DE CARRINHO DE COMPRAS║
╠════════════════════════════════╣
║ 1 - Adicionar produto          ║
║ 2 - Remover produto            ║
║ 3 - Atualizar quantidade       ║
║ 4 - Buscar produto             ║
║ 5 - Visualizar carrinho        ║
║ 6 - Limpar carrinho            ║
║ 7 - Ver ajuda                  ║
║ 0 - Sair                       ║
╚════════════════════════════════╝
```

**Digite `1` para adicionar um produto, `5` para ver o carrinho, etc.**

---

## 📦 Pré-requisitos

- **GCC** (compilador C): `gcc --version`
- **Make**: `make --version`
- Linux, macOS ou WSL (Windows)

### Instalar (se necessário)

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential
```

**macOS:**
```bash
brew install gcc
```

**Windows (WSL):**
```bash
sudo apt-get install build-essential
```

---

## 🎯 Exemplos Rápidos

### Exemplo 1: Adicionar um Produto

```
Escolha uma opcao: 1

--- Adicionar Produto ---
Código do produto: 101
Nome do produto: Notebook
Preço unitário: R$ 3499.99
Quantidade: 1

✓ Produto adicionado com sucesso!
```

### Exemplo 2: Ver o Carrinho

```
Escolha uma opcao: 5

╔════════╦═════════════════════════╦═════════╦══════════╦═══════════════╗
║ Código ║ Produto                 ║ Preço   ║ Qtd      ║ Subtotal      ║
╠════════╬═════════════════════════╬═════════╬══════════╬═══════════════╣
║   1001 ║ Notebook Dell 15"       ║ 3499.99 ║        1 ║ R$  3499.99   ║
║   1002 ║ Mouse Logitech          ║   89.90 ║        2 ║ R$   179.80   ║
║   1003 ║ Teclado Mecânico RGB    ║  450.00 ║        1 ║ R$   450.00   ║
╠════════╩═════════════════════════╩═════════╩══════════╩═══════════════╣
║ Total de itens: 4                            Total: R$ 4129.79         ║
╚═════════════════════════════════════════════════════════════════════════╝
```

### Exemplo 3: Atualizar Quantidade

```
Escolha uma opcao: 3

--- Atualizar Quantidade ---
Código do produto: 1002
Nova quantidade: 5

✓ Quantidade atualizada com sucesso!
```

### Exemplo 4: Buscar um Produto

```
Escolha uma opcao: 4

--- Buscar Produto ---
Código do produto: 1001

✓ Produto encontrado:
  Código:     1001
  Nome:       Notebook Dell 15"
  Preço:      R$ 3499.99
  Quantidade: 1
  Subtotal:   R$ 3499.99
```

---

## 🔧 Comandos Make Úteis

| Comando | O que faz |
|---------|-----------|
| `make` | Compila o projeto |
| `make run` | Compila e executa |
| `make clean` | Remove arquivos compilados |
| `make rebuild` | Limpa e recompila |
| `make debug` | Compila com símbolos de debug |
| `make help` | Mostra todos os comandos |

---

## 🐛 Resolver Problemas

### Erro: "command not found: make"

**Solução:**
```bash
# Ubuntu/Debian
sudo apt-get install make

# macOS
brew install make
```

### Erro: "gcc: command not found"

**Solução:**
```bash
# Ubuntu/Debian
sudo apt-get install gcc

# macOS
brew install gcc
```

### Erro ao compilar: "undefined reference"

**Solução:** Certifique-se de que você está na pasta correta:
```bash
cd shopping-cart/
make clean
make
```

---

## 📚 Próximos Passos

1. **Leia o README.md** para documentação completa
2. **Veja CHANGELOG.md** para histórico de alterações
3. **Execute examples.c** para mais exemplos:
   ```bash
   gcc -Wall -Wextra -std=c99 examples.c shopping_cart.c -o examples
   ./examples
   ```
4. **Estude o código** em `shopping_cart.h` e `shopping_cart.c`

---

## 💡 Dicas Profissionais

### 1. Validação de Entrada
O programa valida automaticamente:
- ✓ Preços negativos são rejeitados
- ✓ Quantidades inválidas são tratadas
- ✓ Produtos duplicados têm quantidade incrementada

### 2. Memória Segura
- Não há vazamentos de memória (memory leaks)
- Sem buffer overflow
- Limpeza automática ao sair

### 3. Interface Amigável
- Menu intuitivo com opções numeradas
- Feedback visual com ✓ e ✗
- Mensagens de erro claras
- Confirmação para operações destrutivas

---

## 🎓 Conceitos Educacionais

Este projeto demonstra:

- ✓ **Listas Encadeadas**: Estruturas de dados dinâmicas
- ✓ **Alocação de Memória**: malloc/free
- ✓ **Ponteiros**: Manipulação de ponteiros em C
- ✓ **Estruturas**: Definição e uso de structs
- ✓ **Modularização**: Separação de código
- ✓ **Documentação**: Padrão Doxygen
- ✓ **Tratamento de Erros**: Códigos de retorno
- ✓ **Programação Defensiva**: Validação de inputs

---

## ❓ Perguntas Frequentes

**P: Os dados são salvos?**  
R: Não. Os dados existem apenas durante a execução. Para persistência, veja CHANGELOG.md.

**P: Posso adicionar o mesmo produto duas vezes?**  
R: Sim! A quantidade será automaticamente incrementada.

**P: Qual é o limite de produtos?**  
R: Nenhum! O sistema usa memória dinâmica.

**P: Posso compilar sem Make?**  
R: Sim! Use: `gcc -Wall -Wextra -std=c99 main.c shopping_cart.c -o shopping_cart`

**P: O código funciona no Windows?**  
R: Sim, se você usar WSL (Windows Subsystem for Linux) ou MinGW.

---

## 📖 Documentação Adicional

- **readme.md** - Documentação completa e referência da API
- **shopping_cart.h** - Definições e protótipos documentados
- **shopping_cart.c** - Implementação com comentários detalhados
- **examples.c** - 7 exemplos práticos de uso
- **CHANGELOG.md** - Histórico de alterações e roadmap futuro

---

## 🎉 Você está pronto!

Parabéns! Você tem um sistema de carrinho de compras totalmente funcional.

**Próximas ideias:**
- Adicione suporte a desconto
- Implemente persistência em arquivo
- Crie uma interface gráfica
- Integre com um banco de dados

Boa sorte! 🚀
