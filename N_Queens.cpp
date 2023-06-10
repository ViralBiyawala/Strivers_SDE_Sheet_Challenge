#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void placeQueens(vector<vector<int>>& board, int row, int n, vector<vector<int>>& solutions) {
    if (row == n) {
        vector<int> config;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                config.push_back(board[i][j]);
            }
        }
        solutions.push_back(config);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            placeQueens(board, row + 1, n, solutions);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> solutions;

    placeQueens(board, 0, n, solutions);

    return solutions;
}
