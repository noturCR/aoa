#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int MAX = 10; // Max size for N

void printSolution(vector<vector<int>> &board, int n) {
    cout << "One of the solutions:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << "\n";
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check this column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row, int n) {
    if (row == n) {
        printSolution(board, n);
        return true; // Return true to print only one solution
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    string input;
    int n;

    cout << "Enter the value of N (number of queens), or press ENTER for default (4): ";
    getline(cin, input);

    if (input.empty()) {
        n = 4; // Default
    } else {
        stringstream ss(input);
        ss >> n;
    }

    if (n < 1 || n > MAX) {
        cout << "Please enter a value between 1 and " << MAX << ".\n";
        return 1;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists for N = " << n << endl;
    }

    return 0;
}
