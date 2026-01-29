
# 🗂️ Gerenciador de Fila em C

---

## 📚 Sobre o Projeto

Este programa implementa uma **fila dinâmica** em linguagem C para gerenciar uma lista de clientes. Ele permite adicionar clientes ao final da fila e atender (remover) clientes do início da fila, simulando uma fila real de atendimento.

---

## 🧠 Conceitos Fundamentais: O Que é uma Fila?

Uma **fila** é uma estrutura de dados que funciona como uma **fila de pessoas no mundo real**. Imagine uma fila no banco ou supermercado:

- **Primeiro a chegar, primeiro a ser atendido** (FIFO - *First In, First Out*).
- A pessoa que chega vai para o **final da fila**.
- O atendente chama quem está no **início da fila**.

### Como isso é representado no código?

| Mundo Real           | Estrutura em C               |
|---------------------|-----------------------------|
| Pessoa (cliente)     | `struct No`                 |
| Fila (ordem de chegada) | `struct Fila` com ponteiros `inicio` e `fim` |
| Chegar na fila      | Função `NovoCliente` adiciona no fim da lista ligada |
| Atender (sair da fila) | Função `atendercliente` remove o primeiro nó da lista |

---

## 🧱 Estrutura do Código

### 1. `struct No`

Representa um cliente na fila:

```c
typedef struct No {
    char nome[30];          // Nome do cliente
    struct No *proximo;     // Ponteiro para o próximo cliente na fila
} No;
```

### 2. `struct Fila`

Guarda informações da fila:

```c
typedef struct Fila {
    No *inicio;             // Primeiro cliente na fila
    No *fim;                // Último cliente na fila
    int tamanho;            // Quantidade de clientes na fila
} Fila;
```

---

## ⚙️ Principais Funções

| Função            | O que faz                                                | Analogia no Mundo Real         |
|-------------------|----------------------------------------------------------|-------------------------------|
| `CriarFila()`      | Inicializa uma fila vazia                                | Criar uma fila sem pessoas    |
| `NovoCliente()`    | Adiciona um cliente ao fim da fila                       | Pessoa entra no final da fila |
| `atendercliente()` | Remove o primeiro cliente da fila (quem será atendido)  | Pessoa atendida sai da fila   |
| `ExibirFila()`     | Mostra a fila atual com a ordem dos clientes             | Visualizar a fila em espera   |

---

## 🚶 Passo a Passo do Funcionamento

1. **Criar a fila** (vazia, sem clientes)
2. **Adicionar clientes** com nome, um a um, sempre no final
3. **Exibir fila** mostrando a ordem de atendimento
4. **Atender clientes** removendo-os do início da fila
5. Repetir até terminar ou sair do programa

---

## 🖼️ Representação Visual da Fila

```
[início] → João → Maria → Carlos → [fim]
```

- `inicio`: ponteiro para o cliente "João" (próximo a ser atendido)
- `fim`: ponteiro para o cliente "Carlos" (último a entrar)
- Setas `→` representam o campo `proximo` que liga um cliente ao próximo na fila

---

## 📝 Exemplo de uso (na prática)

```plaintext
Selecione uma das opcoes abaixo:
1 - Novo Cliente
2 - Atender um cliente
0 - Sair
Opcao: 1
Qual o nome do cliente? Ana
Cliente 'Ana' adicionado à fila.

0 | Ana

Opcao: 1
Qual o nome do cliente? Bruno
Cliente 'Bruno' adicionado à fila.

0 | Ana
1 | Bruno

Opcao: 2
Cliente atendido e removido da fila.

0 | Bruno
```

---

## 💡 Por que usar uma fila?

- **Organização e ordem garantida:** O primeiro a chegar é o primeiro a ser atendido.
- **Flexibilidade:** Diferente de arrays estáticos, esta fila usa **lista ligada**, permitindo crescer dinamicamente sem limites fixos.
- **Aplicações práticas:** Sistemas de atendimento, buffers, escalonadores de processos, sistemas operacionais, etc.

---

## ⚠️ Boas práticas implementadas

- Alocação dinâmica de memória com `malloc` e liberação com `free`
- Manipulação segura de strings com `strcpy`
- Verificação de fila vazia antes de remover elementos
- Limpeza do buffer para entrada correta de strings com espaços

---

## 🛠️ Como compilar e executar

```bash
gcc main.c -o fila
./fila
```

---

## 👨‍💻 Autor

Desenvolvido por **danilosupertech** – aprendizado prático e didático de estruturas de dados em C.

---

## 🎨 Ícones utilizados:

- 🗂️ Estrutura de dados
- 📚 Conceitos
- 🧱 Estrutura
- ⚙️ Funções
- 🚶 Fluxo
- 🖼️ Visualização
- 📝 Exemplo
- 💡 Importância
- ⚠️ Cuidados
- 🛠️ Como usar
- 👨‍💻 Autor

---

Obrigado por conferir! Para dúvidas ou sugestões, abra uma issue.
