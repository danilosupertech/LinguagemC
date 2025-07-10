
# Sistema de Carrinho de Compras com Lista Encadeada em C 🛒

## Visão Geral

Este projeto implementa um sistema simples de carrinho de compras usando **listas ligadas** (ou listas encadeadas) em linguagem C. Ele permite adicionar produtos ao carrinho, listar os produtos presentes e liberar a memória usada ao final.

O código exemplifica o uso de estruturas dinâmicas para armazenar dados de forma flexível, sem precisar definir um tamanho fixo antecipadamente.

---

## Estrutura Conceitual: Lista Encadeada 📋

Uma **lista encadeada** é uma coleção dinâmica de elementos, onde cada elemento (ou nó) contém os dados e um ponteiro para o próximo elemento da lista.  

### Analogia do Mundo Real

Imagine uma fila de pessoas onde cada pessoa sabe quem está atrás dela. Diferente de um grupo fixo, pessoas podem entrar e sair da fila a qualquer momento.  

Aqui, o carrinho é como essa fila de produtos, onde cada produto aponta para o próximo na lista.

---

## Detalhes da Estrutura do Código

### Struct `Carrinho`

```c
typedef struct Carrinho {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    struct Carrinho *proximo;
} Carrinho;
```

- `codigo`: Identificador único do produto
- `nome`: Nome do produto
- `preco`: Preço unitário do produto
- `quantidade`: Quantidade desse produto no carrinho
- `proximo`: Ponteiro para o próximo produto na lista

---

### Funções Principais

| Função              | Descrição                                          |
|---------------------|----------------------------------------------------|
| `adicionarProduto`  | Cria um novo produto e adiciona ao início da lista|
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
