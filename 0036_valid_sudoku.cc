#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9][10]{}, cols[9][10]{}, boxes[3][3][10]{};
    for (int i{}; i < 9; ++i) {
      for (int j{}; j < 9; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int n{board[i][j] - '0'};
        if (rows[i][n] || cols[j][n] || boxes[i / 3][j / 3][n]) {
          return false;
        }
        rows[i][n] = cols[j][n] = boxes[i / 3][j / 3][n] = true;
      }
    }
    return true;
  }
};
