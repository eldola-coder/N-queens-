Description of the N-Queens Solver Program

This C++ program is designed to solve the N-Queens problem using a stack-based backtracking approach. The N-Queens problem involves placing N queens on an N x N chessboard so that no two queens threaten each other, meaning no two queens share the same row, column, or diagonal.

Key Components of the Program

Class cNode

Represents a node in the search tree, which holds a specific board configuration.

Attributes:

char** board: A 2D dynamic array representing the chessboard.

int row: The index of the last row filled with a queen.

int n: The size of the board (number of rows/columns).

cNode* next: Pointer to the next node (used in the stack).

Constructors:

cNode(int size): Initializes an empty board with all positions set to '.'.

cNode(cNode* parent): Copies the board from a parent node and prepares for the next row.

Destructor: Frees dynamically allocated memory for the board.

Class stack

Implements a simple linked-list stack to store cNode objects for backtracking.

Methods:

push(cNode* node): Adds a node to the top of the stack.

pop(): Removes and returns the node from the top of the stack.

Destructor: Frees all remaining nodes in the stack.

Function displayBoard(cNode* node)

Prints the board configuration of a node, showing 'Q' for queens and '.' for empty spaces.

Function solveNQueens(int n)

Implements backtracking using a stack to explore all valid queen placements.

Steps:

Push an empty board onto the stack.

While the stack is not empty:

Pop the top board (current configuration).

Check if the board represents a complete solution. If yes, print it and increment the solution count.

For the next row, try placing a queen in each column:

Check if placing the queen is legal (no threats from existing queens).

If legal, create a new board configuration, place the queen, and push it onto the stack.

Continue until all configurations are explored.

At the end, prints the total number of solutions.

main() Function

Prompts the user to enter the board size (1 to 10).

Calls solveNQueens(n) to compute and display all solutions.

Features

Uses dynamic memory allocation to handle board states of arbitrary sizes (within the range 1–10).

Avoids recursion by using an explicit stack, which can help visualize the backtracking process.

Displays all solutions with a clear board layout.

Computes the total number of solutions for the given board size.
