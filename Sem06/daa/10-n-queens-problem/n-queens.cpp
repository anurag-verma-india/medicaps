#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    // Base case: If all queens are placed
    if (row >= n)
        return true;
    
    // Try placing queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if queen can be placed
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 1;
            
            // Recursively place rest of the queens
            if (solveNQueensUtil(board, row + 1, n))
                return true;
            
            // If placing queen doesn't lead to a solution, backtrack
            board[row][col] = 0; // Backtrack
        }
    }
    
    // If no column placement works in this row
    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if (solveNQueensUtil(board, 0, n)) {
        cout << "Solution exists. The placement of queens is:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    int n = 4; // 4x4 chessboard
    cout << "N-Queens Problem for " << n << "x" << n << " board:" << endl;
    solveNQueens(n);
    return 0;
}
