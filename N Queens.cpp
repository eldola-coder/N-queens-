#include <iostream>
using namespace std;

class cNode {
public:
    char** board;
    int row;
    int n;
    cNode* next;

    cNode(int size) {
        n = size;
        row = -1;
        next = NULL;

        board = new char* [n];
        for (int i = 0; i < n; i++) {
            board[i] = new char[n];
            for (int j = 0; j < n; j++)
                board[i][j] = '.';
        }
    }

    cNode(cNode* parent) {
        n = parent->n;
        row = parent->row + 1;
        next = NULL;

        board = new char* [n];
        for (int i = 0; i < n; i++) {
            board[i] = new char[n];
            for (int j = 0; j < n; j++)
                board[i][j] = parent->board[i][j];
        }
    }

    ~cNode() {
        for (int i = 0; i < n; i++)
            delete[] board[i];
        delete[] board;
    }
};

class stack {
public:
    cNode* PH;

    stack() { PH = NULL; }

    void push(cNode* node) {
        node->next = PH;
        PH = node;
    }

    cNode* pop() {
        if (PH == NULL) return NULL;
        cNode* temp = PH;
        PH = PH->next;
        return temp;
    }

    ~stack() {
        while (PH != NULL) {
            cNode* temp = pop();
            delete temp;
        }
    }
};

void displayBoard(cNode* node) {
    for (int i = 0; i < node->n; i++) {
        for (int j = 0; j < node->n; j++)
            cout << node->board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int n) {
    stack S;
    int solutionCount = 0;
    S.push(new cNode(n));

    while (S.PH != NULL) {
        cNode* parent = S.pop();
        int currentRow = parent->row + 1;

        int deleted = 0; 

        if (currentRow == n) {
            solutionCount++;
            cout << "Solution " << solutionCount << ":\n";
            displayBoard(parent);
            delete parent;
            deleted = 1;
        }

        for (int col = 0; col < n; col++) {
            int legal = 1;
            for (int r = 0; r <= parent->row; r++) {
                for (int c = 0; c < n; c++) {
                    if (parent->board[r][c] == 'Q') {
                        if (c == col) legal = 0;
                        if ((r - currentRow) == (c - col)) legal = 0;
                        if ((r - currentRow) == (col - c)) legal = 0;
                        if (legal == 0) break;
                    }
                }
                if (legal == 0) break;
            }

            if (legal == 1 && currentRow < n) {
                cNode* child = new cNode(parent);
                child->board[currentRow][col] = 'Q';
                S.push(child);
            }
        }

        if (!deleted) delete parent;
    }

    cout << "Total solutions: " << solutionCount << endl;
}

int main() {
    int n;
    cout << "Enter board size (1-10): ";
    cin >> n;
    if (n < 1 || n > 10) return 0;

    solveNQueens(n);
}
