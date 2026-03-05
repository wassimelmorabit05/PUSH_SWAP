# push_swap

*This project has been created as part of the 42 curriculum by oel-mora.*

---

## Description

**push_swap** is a sorting algorithm project from the 42 Network.

The goal is to sort a stack of integers using **two stacks (`a` and `b`)** and a **limited set of allowed operations**, while producing the **smallest possible number of instructions**.

The program receives a list of integers as arguments and prints the sequence of operations required to sort them.

This implementation uses an optimized **Chunk-based sorting strategy** to efficiently handle both small and large inputs.

---

## Objectives

* Understand stack-based sorting techniques
* Design efficient algorithms under strict constraints
* Minimize the number of operations
* Follow the 42 coding standard (Norm)

---

## Allowed Operations

The program can only use the following instructions:

```
sa  swap the first two elements of stack a
sb  swap the first two elements of stack b
ss  sa and sb at the same time

pa  push the first element of b onto a
pb  push the first element of a onto b

ra  rotate a (first element becomes last)
rb  rotate b
rr  ra and rb at the same time

rra reverse rotate a
rrb reverse rotate b
rrr rra and rrb at the same time
```

---

## Algorithm Used — Chunk Strategy

This implementation uses a **chunk-based sorting algorithm**.

### 1.Indexing

All values are converted into their **sorted indexes**:

Example:

```
40 10 30 20
↓
3 0 2 1
```

This simplifies comparisons and improves algorithm performance.

---

### 2.Chunk Division

The index range is divided into **chunks**:

| Input Size | Chunk Size |
| ---------- | ---------- |
| ≤ 100      | 18         |
| ≤ 500      | 35         |
| > 500      | size / 12  |

---

### 3.Push Phase (A → B)

Elements are pushed from **stack A to stack B** depending on their index:

* very small values → `pb`
* chunk values → `pb` + `rb`
* others → `ra`

This keeps smaller numbers toward the bottom of stack **B**.

---

### 4.Rebuild Phase (B → A)

The largest element in **B** is always moved to the top using:

```
rb  or  rrb
```

Then pushed back to **A** using:

```
pa
```

This reconstructs the sorted stack.

---

## Performance

The algorithm satisfies the push_swap evaluation requirements:

| Input       | Expected Operations |
| ----------- | ------------------- |
| 100 numbers | < 700               |
| 500 numbers | < 5500              |

---

## Instructions

### Error Handling
The program prints `Error` to stderr and exits with status code 1 when:
- A non-integer argument is provided
- An argument exceeds `INT_MAX` or `INT_MIN`
- Duplicate values are present
- An empty string is given

### Compilation

Compile the project using:

```bash
make
```
This will generate the executable :

```bash
./push_swap
```

To recompile everything :

```bash
make re
```
### Execution

Run the program with integers as arguments : 
```bash
./push_swap 2 1 3 6 5 8
```
You can also pass space-separated numbers inside quotes :
```bash
./push_swap "3 2 1"
```

The program prints the sequence of operations needed to sort the numbers in ascending order.

If the input is invalid (non-numeric values, duplicates, overflow, or empty input), the program prints :
```bash
Error
```

## Resources

* push_swap subject — official project specifications
* Push Swap: The Least Amount of Moves with Two Stacks
  https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
* Articles and discussions about push_swap optimization 

## AI Usage

AI was used for :
 - explaining the Chunk Strategy algorithm