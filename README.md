N-Queens Solver (C++ – Stack-Based Backtracking)

This project provides a complete C++ implementation of the N-Queens problem using an explicit stack-based backtracking algorithm.
The goal of the N-Queens puzzle is to place N queens on an N × N chessboard such that no two queens threaten each other. This implementation avoids recursion and instead uses a custom stack to manage the search tree.

Table of Contents:
__________________
1-Overview
2-Features
3-How It Works
3.1-Class cNode
3.2-Class stack
4-Backtracking Logic
5-Example Output
6-How to Compile and Run
7-Use Cases
8-License
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Overview

The program explores all valid queen placements on an N × N chessboard, prints every valid configuration, and displays the total number of solutions.
It supports board sizes from 1 to 10 and uses dynamic memory allocation, making it flexible and efficient.
                                 - - - -  - - -  - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Features:
_________
*Non-recursive backtracking using a custom stack
*Dynamic board allocation for arbitrary sizes (1–10)
*Prints all valid board configurations
*Counts the total number of solutions
*Clean object-oriented structure
*Easy-to-read board visualization
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - 
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - - 
How It Works:
_____________
Class cNode
Represents a single board configuration in the search process.
Attributes
char\*\* board — 2D dynamic array representing the board
int row — index of the last row where a queen was placed
int n — board size
cNode\* next — pointer used by the stack
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - -

Constructors:
_____________
cNode(int size) — creates an empty board filled with .
cNode(cNode\* parent) — copies parent board and advances to next row
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
Destructor:
___________
Frees all allocated memory for the board
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
Class stack:
____________
A simple linked-list stack used to store cNode objects during backtracking.
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                          - - - - - - - - - - - - - - - - - - - - - - - - - -
Methods:
_______
push(cNode\* node) — pushes a board configuration
pop() — removes and returns the top configuration
Destructor cleans all remaining nodes
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                         - - - - - - - - - - - - - - - - - - - - - - - - - -
Backtracking Logic:
___________________
*Implemented in solveNQueens(int n):
Start by pushing an empty board onto the stack.
*While the stack is not empty:
Pop the current board.
If all rows are filled with queens → print the solution.
Otherwise, try each column in the next row.
For each column:
Check if placing a queen is safe.
If safe → create a new node, place the queen, and push onto the stack.
Continue until all configurations have been explored.
At the end, the program prints the total number of solutions.

Example Output (N = 4)
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
and also the other cases from(1-10)
