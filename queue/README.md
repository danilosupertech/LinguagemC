
# 🗂️ Queue Manager in C

---

## 📚 About the Project

This program implements a **dynamic queue** in C language to manage a list of customers. It allows adding customers to the end of the queue and serving (removing) customers from the beginning, simulating a real service queue.

---

## 🧠 Fundamental Concepts: What is a Queue?

A **queue** is a data structure that works like a **real-world queue**. Imagine standing in line at a bank or supermarket:

- **First to arrive, first to be served** (FIFO - *First In, First Out*).
- The person who arrives goes to the **end of the queue**.
- The attendant calls whoever is at the **beginning of the queue**.

### How is this represented in code?

| Real World | C Structure |
|---|---|
| Person (customer) | `struct No` |
| Queue (order of arrival) | `struct Fila` with `inicio` and `fim` pointers |
| Arrive in queue | Function `NovoCliente` adds at the end of linked list |
| Serve (leave queue) | Function `atendercliente` removes first node from list |

---

## 🧱 Code Structure

### 1. `struct No`

Represents a customer in the queue:

```c
typedef struct No {
    char nome[30];          // Customer name
    struct No *proximo;     // Pointer to next customer in queue
} No;
```

### 2. `struct Fila`

Stores queue information:

```c
typedef struct Fila {
    No *inicio;             // First customer in queue
    No *fim;                // Last customer in queue
    int tamanho;            // Number of customers in queue
} Fila;
```

---

## ⚙️ Main Functions

| Function | What it does | Real-World Analogy |
|---|---|---|
| `CriarFila()` | Initializes an empty queue | Create a queue with no people |
| `NovoCliente()` | Adds a customer to the end of queue | Person enters at end of line |
| `atendercliente()` | Removes first customer from queue (who gets served) | Person served leaves queue |
| `ExibirFila()` | Shows current queue with order of customers | View the waiting queue |

---

## 🚶 Step-by-Step Operation

1. **Create the queue** (empty, no customers)
2. **Add customers** with name, one by one, always at the end
3. **Display queue** showing the service order
4. **Serve customers** by removing them from the beginning
5. Repeat until finish or exit program

---

## 🖼️ Visual Representation of Queue

```
[start] → João → Maria → Carlos → [end]
```

- `inicio`: pointer to customer "João" (next to be served)
- `fim`: pointer to customer "Carlos" (last to enter)
- Arrows `→` represent the `proximo` field linking one customer to the next

---

## 📝 Usage Example (in practice)

```plaintext
Select one of the options below:
1 - New Customer
2 - Serve a customer
0 - Exit
Option: 1
What is the customer's name? Ana
Customer 'Ana' added to queue.

0 | Ana

Option: 1
What is the customer's name? Bruno
Customer 'Bruno' added to queue.

0 | Ana
1 | Bruno

Option: 2
Customer served and removed from queue.

0 | Bruno
```

---

## 💡 Why use a queue?

- **Organization and guaranteed order:** First to arrive is first to be served.
- **Flexibility:** Unlike static arrays, this queue uses **linked list**, allowing dynamic growth without fixed limits.
- **Practical applications:** Service systems, buffers, process schedulers, operating systems, etc.

---

## ⚠️ Best practices implemented

- Dynamic memory allocation with `malloc` and deallocation with `free`
- Safe string manipulation with `strcpy`
- Check for empty queue before removing elements
- Buffer cleanup for correct input of strings with spaces

---

## 🧪 Testing

Run the test suite to verify compilation and functionality:

```bash
bash test.sh
```

**What the tests cover:**
- ✓ Source file existence
- ✓ Compilation with strict GCC flags (-Wall -Wextra -std=c99)
- ✓ Function verification (looks for `atender` and `Novo` functions)
- ✓ Program execution and basic functionality
- ✓ Memory check with valgrind (if available)
- ✓ Code quality and warnings

**Test output example:**
```
╔════════════════════════════════════════════════╗
║      Queue/Fila - Test Suite                  ║
╚════════════════════════════════════════════════╝

Testing: Files exist... ✓ PASSED
Testing: Compilation... ✓ PASSED
Testing: Functions found... ✓ PASSED
Testing: Execution... ✓ PASSED
Testing: Memory checks... ✓ PASSED

╔════════════════════════════════════════════════╗
║         TEST RESULTS SUMMARY                  ║
╠════════════════════════════════════════════════╣
║ Tests Passed: 5 ✓
║ Tests Failed:  0
╚════════════════════════════════════════════════╝
```

---

## 🛠️ How to Compile and Run

### Option 1: With test script (recommended)

```bash
bash test.sh
```

### Option 2: Manual compilation

```bash
gcc main.c -o fila
./fila
```

---

## 👨‍💻 Author

Developed by **danilosupertech** – practical and educational learning of data structures in C.

---

## 🎨 Icons used:

- 🗂️ Data structure
- 📚 Concepts
- 🧱 Structure
- ⚙️ Functions
- 🚶 Flow
- 🖼️ Visualization
- 📝 Example
- 💡 Importance
- ⚠️ Best practices
- 🛠️ How to use
- 👨‍💻 Author

---

Thank you for checking this out! For questions or suggestions, open an issue.
