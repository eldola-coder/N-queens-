# N-Queens Solver (C++ – Stack-Based Backtracking)

This repository contains a complete C++ implementation of the **N-Queens** problem using an explicit **stack-based backtracking** algorithm (non-recursive). The goal is to place **N queens** on an **N × N** chessboard so no two queens attack each other (no shared row, column, or diagonal).

---

## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [How It Works](#how-it-works)
   - [Class `cNode`](#class-cnode)
   - [Class `stack`](#class-stack)
4. [Backtracking Logic](#backtracking-logic)
5. [Example Output](#example-output)
6. [Solutions for N = 1..10](#solutions-for-n--110)
7. [How to Compile and Run](#how-to-compile-and-run)
8. [Use Cases](#use-cases)
9. [License](#license)

---

## 1 - Overview

The program enumerates all valid queen placements on an `N × N` chessboard, prints each configuration in a clear board layout, and reports the total number of solutions. The implementation supports board sizes from **1 to 10** and uses dynamic memory allocation to represent board states. It avoids recursion by using a custom stack to manage states, which makes the backtracking process explicit and easier to debug or visualize.

---

## 2 - Features

- Non-recursive backtracking using an explicit stack.
- Dynamic board allocation for arbitrary sizes (1–10).
- Prints every valid board configuration and a separator between solutions.
- Counts and reports the total number of solutions.
- Modular, object-oriented code structure.
- Optional mode to run all sizes from 1 through 10.

---

## 3 - How It Works

At a high level the program represents each board configuration as a `cNode` object. Each `cNode` contains a complete copy of the board state and an index indicating the last row filled. A linked-list `stack` stores `cNode*` values. The main search loop pops a state, tests completion or expands the next row by creating child states for each legal queen placement.

### 3.1 - Class `cNode`

Represents a single board configuration in the search tree.

**Attributes**
- `char** board` — 2D dynamic array representing the board ('.' empty, 'Q' queen)
- `int row` — index of the last filled row (starts at `-1` for an empty board)
- `int n` — board size

**Constructors**
- `cNode(int size)` — create an empty board filled with `.`
- `cNode(const cNode* parent)` — deep-copy parent board and prepare for the next row

**Destructor**
- Frees the allocated board memory

### 3.2 - Class `stack`

A small linked-list stack that stores `cNode*` for backtracking.

**Methods**
- `push(cNode* node)` — push a board configuration onto the stack
- `pop()` — remove and return the top configuration (returns `nullptr` if empty)
- Destructor — frees any leftover nodes and their `cNode` payloads

---

## 4 - Backtracking Logic

Implemented in `solveNQueens(int n)` (or similar). The algorithm:

1. Push an initial empty `cNode` onto the stack.
2. While the stack is not empty:
   - Pop the top `cNode`.
   - If the popped node has `row == n - 1`, it is a complete and valid solution — print it and increment the solution counter.
   - Otherwise, attempt to place a queen in `row + 1` for every column `0..n-1`:
     - If placing a queen at `(row + 1, col)` is safe (no existing queens in same column or diagonals), then:
       - Create a deep copy of the current node, place the queen, update `row`, and push the new node onto the stack.
3. Continue until the stack is exhausted.
4. Print the total number of solutions.

This approach enumerates the entire search space like a depth-first traversal but without recursion.

---

## 5 - Example Output

For `N = 4`, the program prints two solutions (each board followed by a separator):

```
. Q . .
. . . Q
Q . . .
. . Q .

---

. . Q .
Q . . .
. . . Q
. Q . .

---

Total solutions = 2
```

---

## 6 - Solutions for N = 1..10

| N | Solutions |
|---:|----------:|
| 1 | 1 |
| 2 | 0 |
| 3 | 0 |
| 4 | 2 |
| 5 | 10 |
| 6 | 4 |
| 7 | 40 |
| 8 | 92 |
| 9 | 352 |
|10 | 724 |

> These are the well-known, verified counts for the N-Queens problem.

---

## 7 - How to Compile and Run

Place your C++ source file (for example `main.cpp`) in the repository root.

### Compile (GNU g++)

```bash
g++ -std=c++17 -O2 -o nqueens main.cpp
```

### Run — single size

```bash
./nqueens
```

The program will prompt for a board size between 1 and 10. Enter a number to compute solutions for that size. Some implementations accept `0` to run all sizes from 1 through 10 sequentially and print the results.

---

## 8 - Use Cases

- Educational demonstration of backtracking and search techniques.
- Visualizing non-recursive depth-first exploration.
- Practice with dynamic memory and object copying in C++.
- Small-scale benchmarking of different N-Queens solving strategies.

---

## 9 - License

This project is released under the **MIT License**. You are free to use, modify, and distribute the code with attribution.

---
