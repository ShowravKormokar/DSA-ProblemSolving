// Leetcode problem 36 -> Valid Sudoku
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<string> seen;

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
                continue;
            const string c(1, board[i][j]);
            if (!seen.insert(c + "@row" + to_string(i)).second ||
                !seen.insert(c + "@col" + to_string(j)).second ||
                !seen.insert(c + "@box" + to_string(i / 3) + to_string(j / 3))
                     .second)
                return false;
        }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "Result: " << isValidSudoku(board) << endl; // Output: True
    return 0;
}

/*
TC: O(1)
SC: O(1)
*/