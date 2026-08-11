#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Horizontal safety
    for(int j = 0; j < n; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }
    // Vertical safety
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }
    // Left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    // Right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
void nQueens(vector<string> board, int row, int n,vector<vector<string>>& ans) {
    // All queens are placed
    if(row == n) {
        ans.push_back(board);
        return;
    }
    // Try every column in current row
    for(int j = 0; j < n; j++) {

        if(isSafe(board, row, j, n)) {

            board[row][j] = 'Q';

            nQueens(board, row + 1, n, ans);

            // Backtracking
            board[row][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}