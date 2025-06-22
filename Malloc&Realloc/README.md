# Implementação de Lista Encadeada em C

## Objetivo
Demonstrar os princípios fundamentais de:
- Alocação dinâmica de memória
- Estruturas de dados encadeadas
- Gerenciamento manual de memória
- Operações básicas em listas encadeadas

## Funcionalidades Implementadas
1. Criação dinâmica de nós
2. Inserção no final da lista (O(1))
3. Travessia/impressão da lista
4. Desalocação completa de memória
5. Tratamento básico de erros de alocação

## Fluxo do Programa
```mermaid
graph TD
    A[Início] --> B{Lista vazia?}
    B -->|Sim| C[Cria primeiro nó]
    B -->|Não| D[Insere no final]
    C --> E[Atualiza inicio/fim]
    D --> E
    E --> F{Continuar?}
    F -->|Não| G[Imprimir lista]
    G --> H[Liberar memória]
    F -->|Sim| B
	
	
gcc -std=c99 -Wall lista_encadeada.c -o lista
./lista


## 🚀 Melhorias Futuras

O código atual pode ser expandido com as seguintes melhorias:

- **Modularização (separar em funções):**  
  Dividir em funções específicas para:
  - `inserir_no_fim()`
  - `imprimir_lista()`
  - `liberar_lista()`

- **Validação de entrada do usuário:**  
  Implementar verificações robustas para:
  - Valores numéricos inválidos
  - Caracteres inválidos na opção de parada

- **Implementação de operações adicionais:**
  - Inserção no início
  - Remoção de elementos por valor
  - Busca de valores na lista
  - Inversão da lista

- **Transformar em biblioteca reutilizável:**
  - Criar header file (`lista.h`)
  - Implementar API consistente
  - Documentar interface pública

- **Implementar testes unitários:**
  - Usar framework como Unity ou Check
  - Cobrir casos de borda e falhas
  - Automatizar com ferramentas CI

## 🧠 Contexto de Desenvolvimento

Este código foi desenvolvido como parte de um estudo sobre:

- **Estruturas de dados fundamentais:**  
  Implementação prática de listas encadeadas como base para estruturas mais complexas

- **Gerenciamento manual de memória em C:**  
  Demonstração explícita de:
  - `malloc()` para alocação dinâmica
  - `free()` para liberação de memória
  - Prevenção de memory leaks

- **Boas práticas para prevenção de erros:**
  - Verificação de falhas na alocação
  - Inicialização correta de ponteiros
  - Gerenciamento de recursos

- **Demonstração de ponteiros e estruturas encadeadas:**
  - Relacionamento entre nós
  - Travessia de listas
  - Manipulação de endereços de memória

## 📊 Notas Técnicas

| Característica | Detalhe | Observações |
|----------------|---------|-------------|
| **Complexidade de Inserção** | O(1) no final | Graças ao ponteiro `fim` |
| **Uso de Memória** | 16 bytes/nó (64-bit) | 4 bytes `int` + 8 bytes ponteiro + alinhamento |
| **Segurança** | Verificação de alocação | Prevenção contra NULL pointer dereference |
| **Portabilidade** | C99 puro | Compatível com qualquer compilador padrão |
| **Pilha vs Heap** | Todos os nós no Heap | Alocação dinâmica permite crescimento ilimitado |