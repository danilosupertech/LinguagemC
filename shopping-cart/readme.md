# Shopping Cart System in C 🛒

> A professional and educational implementation of a shopping cart management system using **linked lists** in C language.

## 📋 Overview

This project implements a **dynamic shopping cart** with comprehensive product management features. The structure uses **linked lists** to store products flexibly, allowing adding, removing, and managing items in real-time.

The code was developed following **professional C programming standards**, including:
- Complete Doxygen documentation
- Robust error handling
- Clear separation between interface and implementation
- Interactive user interface
- Efficient dynamic memory usage

### Conceptual Structure: Linked List 📊

A **linked list** is a dynamic collection where each element (node) contains data and a pointer to the next element.

```
[Product 1] → [Product 2] → [Product 3] → NULL
```

**Advantages:**
- Flexible size (no predefined limit)
- Efficient insertion/removal at the beginning
- Uses only necessary memory

---

## 🎯 Features

| Feature | Description |
|---|---|
| **Add Product** | Inserts new product or increments quantity if it already exists |
| **Remove Product** | Removes specific product from cart |
| **Update Quantity** | Modifies product quantity |
| **Search Product** | Finds and displays product details |
| **View Cart** | Displays formatted table with all items and total |
| **Clear Cart** | Removes all products from cart |
| **Calculate Total** | Automatically calculates total price and quantity |

---

## 📁 Project Structure

```
shopping-cart/
├── shopping_cart.h          # Header with definitions and prototypes
├── shopping_cart.c          # Function implementation
├── main.c                   # Interface interativa com usuário
├── Makefile                 # Script para compilação
├── readme.md                # Este arquivo
└── bin/                     # Diretório de saída (gerado)
    └── shopping_cart        # Executável compilado
```

---

## 🔧 Estruturas de Dados

### Enum: `CartStatus`

Códigos de retorno para operações:

```c
typedef enum {
    CART_SUCCESS = 0,           // Operação bem-sucedida
    CART_ERROR_MALLOC = -1,     // Falha de alocação
    CART_ERROR_INVALID_INPUT = -2, // Entrada inválida
    CART_ERROR_NOT_FOUND = -3,  // Produto não encontrado
    CART_ERROR_EMPTY = -4       // Carrinho vazio
} CartStatus;
```

### Struct: `Product`

Representa um produto no carrinho:

```c
typedef struct Product {
    int code;                       // Código único do produto
    char name[100];                 // Nome do produto (até 99 chars)
    float unit_price;               // Preço unitário
    int quantity;                   // Quantidade no carrinho
    struct Product *next;           // Ponteiro para próximo produto
} Product;
```

### Struct: `ShoppingCart`

Encapsula a lista de produtos:

```c
typedef struct {
    Product *head;      // Primeiro produto da lista
    size_t item_count;  // Número total de itens distintos
} ShoppingCart;
```

---

## 📚 Referência da API

### Inicialização e Destruição

#### `ShoppingCart* cart_create(void)`
Cria um novo carrinho vazio.

**Retorno:** Ponteiro para `ShoppingCart` ou `NULL` em caso de falha.

```c
ShoppingCart *cart = cart_create();
if (!cart) {
    printf("Erro ao criar carrinho\n");
    return;
}
```

---

#### `void cart_destroy(ShoppingCart *cart)`
Libera toda a memória do carrinho (produtos + estrutura).

```c
cart_destroy(cart);  // cart não deve mais ser acessado
```

---

### Gerenciamento de Produtos

#### `CartStatus cart_add_product(ShoppingCart *cart, int code, const char *name, float unit_price, int quantity)`
Adiciona um produto ao carrinho ou incrementa sua quantidade se já existe.

**Parâmetros:**
- `cart`: Carrinho alvo
- `code`: ID único do produto
- `name`: Nome do produto (máx. 99 caracteres)
- `unit_price`: Preço unitário (deve ser ≥ 0)
- `quantity`: Quantidade (deve ser > 0)

**Retorno:** `CART_SUCCESS` ou código de erro

**Exemplo:**
```c
CartStatus status = cart_add_product(cart, 101, "Notebook", 3499.99f, 1);
if (status == CART_SUCCESS) {
    printf("Produto adicionado!\n");
}
```

---

#### `CartStatus cart_remove_product(ShoppingCart *cart, int code)`
Remove um produto específico do carrinho.

**Retorno:** `CART_SUCCESS` ou `CART_ERROR_NOT_FOUND`

```c
if (cart_remove_product(cart, 101) == CART_SUCCESS) {
    printf("Produto removido!\n");
}
```

---

#### `CartStatus cart_update_quantity(ShoppingCart *cart, int code, int new_quantity)`
Atualiza a quantidade de um produto.

**Parâmetros:**
- `new_quantity`: Nova quantidade (> 0) ou remove se ≤ 0

```c
cart_update_quantity(cart, 101, 5);  // Atualiza para 5 unidades
```

---

#### `Product* cart_find_product(const ShoppingCart *cart, int code)`
Busca um produto por código.

**Retorno:** Ponteiro para `Product` ou `NULL`

```c
Product *p = cart_find_product(cart, 101);
if (p) {
    printf("Encontrado: %s - R$ %.2f\n", p->name, p->unit_price);
}
```

---

### Informações e Visualização

#### `float cart_calculate_total(const ShoppingCart *cart)`
Calcula o valor total do carrinho.

**Retorno:** Soma de (preço × quantidade) para todos os produtos

```c
float total = cart_calculate_total(cart);
printf("Total: R$ %.2f\n", total);
```

---

#### `int cart_count_total_items(const ShoppingCart *cart)`
Conta o número total de itens (soma de quantidades).

```c
int items = cart_count_total_items(cart);
printf("Total de itens: %d\n", items);
```

---

#### `void cart_print(const ShoppingCart *cart)`
Exibe o carrinho em uma tabela formatada com bordas e totalizações.

```
╔════════╦═════════════════════════╦═════════╦══════════╦═══════════════╗
║ Código ║ Produto                 ║ Preço   ║ Qtd      ║ Subtotal      ║
╠════════╬═════════════════════════╬═════════╬══════════╬═══════════════╣
║   1001 ║ Notebook Dell 15"       ║ 3499.99 ║        1 ║ R$  3499.99   ║
║   1002 ║ Mouse Logitech          ║   89.90 ║        2 ║ R$   179.80   ║
║   1003 ║ Teclado Mecânico RGB    ║  450.00 ║        1 ║ R$   450.00   ║
╚════════╩═════════════════════════╩═════════╩══════════╩═══════════════╝
```

---

#### `void cart_clear(ShoppingCart *cart)`
Remove todos os produtos, deixando o carrinho vazio.

```c
cart_clear(cart);  // cart continua válido
```

---

## 🧪 Testing

Run the comprehensive test suite:

```bash
bash test.sh
```

**What the tests cover:**
- ✓ File existence and integrity
- ✓ Compilation with strict GCC flags (-Wall -Wextra -pedantic)
- ✓ Memory leak detection (valgrind)
- ✓ Function availability and correctness
- ✓ Code quality and warnings
- ✓ Documentation validation
- ✓ Example programs execution
- ✓ Expected output verification

**Test output:**
```
╔════════════════════════════════════════════════╗
║    Shopping Cart - Test Suite                 ║
╚════════════════════════════════════════════════╝

Testing: Files exist... ✓ PASSED
Testing: Compilation... ✓ PASSED
Testing: Functions exist... ✓ PASSED
Testing: Memory (valgrind)... ✓ PASSED
Testing: Warnings... ✓ PASSED
Testing: Documentation... ✓ PASSED
Testing: Examples execution... ✓ PASSED
...
╔════════════════════════════════════════════════╗
║         TEST RESULTS SUMMARY                  ║
╠════════════════════════════════════════════════╣
║ Tests Passed: 11 ✓
║ Tests Failed:  0
╚════════════════════════════════════════════════╝
```

---

## 🚀 Compilação e Execução

### Opção 1: Usar Makefile (Recomendado)

```bash
cd shopping-cart
make              # Compila o projeto
make run          # Executa o programa
make clean        # Remove arquivos compilados
```

### Opção 2: Compilação Manual

```bash
gcc -Wall -Wextra -std=c99 -o shopping_cart main.c shopping_cart.c

# Executar
./shopping_cart
```

### Opção 3: Com Debug (símbolos de depuração)

```bash
gcc -Wall -Wextra -g -std=c99 -o shopping_cart main.c shopping_cart.c

# Usar com gdb
gdb ./shopping_cart
```

---

## 💡 Exemplo de Uso

```c
#include "shopping_cart.h"
#include <stdio.h>

int main(void) {
    // Criar carrinho
    ShoppingCart *cart = cart_create();
    
    // Adicionar produtos
    cart_add_product(cart, 1001, "Notebook", 3499.99f, 1);
    cart_add_product(cart, 1002, "Mouse", 89.90f, 2);
    
    // Exibir
    cart_print(cart);
    
    // Buscar
    Product *p = cart_find_product(cart, 1001);
    if (p) {
        printf("Encontrado: %s\n", p->name);
    }
    
    // Atualizar quantidade
    cart_update_quantity(cart, 1002, 3);
    
    // Calcular total
    printf("Total: R$ %.2f\n", cart_calculate_total(cart));
    
    // Limpar
    cart_destroy(cart);
    
    return 0;
}
```

---

## 🎮 Interface Interativa

O programa `main.c` oferece um menu interativo:

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

### Fluxo de Operação:

1. **Ao iniciar**: Carrinho pré-carregado com produtos de exemplo
2. **Menu principal**: Escolha uma operação (1-7 ou 0 para sair)
3. **Entrada de dados**: O programa guia você
4. **Validação**: Inputs são validados antes de processar
5. **Feedback**: Mensagens claras de sucesso ou erro

---

## ⚠️ Tratamento de Erros

O sistema trata os seguintes cenários:

| Erro | Causa | Solução |
|---|---|---|
| `CART_ERROR_MALLOC` | Sem memória | Liberar outros recursos |
| `CART_ERROR_INVALID_INPUT` | Dados inválidos | Fornecer valores válidos |
| `CART_ERROR_NOT_FOUND` | Produto não existe | Verificar código do produto |
| `CART_ERROR_EMPTY` | Carrinho vazio | Adicionar produtos primeiro |

---

## 🔒 Boas Práticas Implementadas

✅ **Validação robusta**: Todos os inputs são validados  
✅ **Tratamento de memória**: Sem vazamentos (memory leaks)  
✅ **Documentação Doxygen**: Todas as funções documentadas  
✅ **Separação de responsabilidades**: Header + implementação  
✅ **Segurança de strings**: Uso de `strncpy` para evitar overflow  
✅ **Código limpo**: Formatação e nomenclatura profissional  
✅ **Compilação segura**: Flags `-Wall -Wextra` habilitadas  

---

## 📖 Conceitos Aprendidos

- ✓ Listas encadeadas (singly linked lists)
- ✓ Alocação dinâmica de memória (`malloc`, `free`)
- ✓ Ponteiros e estruturas
- ✓ Manipulação de strings segura
- ✓ Documentação de código (Doxygen)
- ✓ Tratamento de erros em C
- ✓ Modularização de código
- ✓ Interfaces CLI (Command-Line Interface)

---

## 🔍 Complexidade Computacional

| Operação | Tempo | Espaço |
|---|---|---|
| Adicionar | O(1) | O(1) |
| Remover | O(n) | O(1) |
| Buscar | O(n) | O(1) |
| Listar | O(n) | O(1) |
| Calcular total | O(n) | O(1) |

*n = número de produtos distintos*

---

## 🚧 Possíveis Melhorias Futuras

- [ ] Persistência em arquivo (salvar/carregar carrinho)
- [ ] Ordenação de produtos (por código, preço, etc.)
- [ ] Desconto por quantidade
- [ ] Histórico de operações (undo/redo)
- [ ] Categoria de produtos
- [ ] Cupons e promoções
- [ ] Interface gráfica (GTK, QT)
- [ ] Serialização JSON

---

## 👤 Autor

**Danilo Côrtes Gonçalves**  
Desenvolvedor | Estudante de Programação em C

---

## 📄 Licença

Este projeto é fornecido como material educacional livre para uso e modificação.

---

## 📞 Contato e Suporte

Para dúvidas ou sugestões sobre o código:
- Consulte os comentários no arquivo de implementação
- Revise a documentação Doxygen nos headers
- Teste os exemplos fornecidos

---

**Versão:** 2.0  
**Data:** 2026-01-29  
**Última atualização:** 2026-01-29
| `listarProdutos`    | Percorre a lista e imprime os produtos              |
| `liberarCarrinho`   | Libera a memória alocada para os produtos           |

---

### Fluxo do Programa

1. O programa inicia com um carrinho vazio (`NULL`).
2. Produtos são adicionados dinamicamente no início da lista.
3. A lista de produtos é exibida.
4. Ao final, toda a memória alocada é liberada para evitar vazamentos.

---

## Benefícios do Uso de Listas Encadeadas

- **Tamanho dinâmico**: Não precisa definir quantidade máxima de produtos antes.
- **Inserção rápida**: Adicionar produtos no início é eficiente.
- **Flexibilidade**: Pode crescer e diminuir conforme necessário.

---

## Observação sobre a implementação

- Os produtos são adicionados no início da lista, então a ordem exibida será inversa à ordem de inserção.
- Em um cenário real, pode ser interessante implementar inserção no fim ou ordenação.

---

## Executando o Código

Compile com:

```bash
gcc nome_do_arquivo.c -o carrinho
./carrinho
```

---

## Exemplo de saída

```
--- Lista de Produtos ---
Codigo: 103
Produto: Macarrao
Preco: R$ 4.99
Quantidade: 3

Codigo: 102
Produto: Feijao
Preco: R$ 8.50
Quantidade: 1

Codigo: 101
Produto: Arroz
Preco: R$ 25.90
Quantidade: 2
```

---

## Conclusão

Este código é um exemplo didático para entender listas encadeadas em C, estrutura de dados fundamental para manipulação dinâmica de dados, muito útil em sistemas como carrinhos de compras, filas, e muito mais.

---

## Ícones e imagens

🛒 Carrinho de compras  
📋 Lista e dados  
⚙️ Código e funções  

---

Obrigado por conferir!  
Qualquer dúvida, só chamar. 😊
