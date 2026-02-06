#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    bool rows[9][10]{}, cols[9][10]{}, boxes[3][3][10]{};
    for (int i{}; i < 9; ++i) {
      for (int j{}; j < 9; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int n{board[i][j] - '0'};
        rows[i][n] = cols[j][n] = boxes[i / 3][j / 3][n] = true;
      }
    }
    auto dfs = [&](auto&& self, int r, int c) -> bool {
      if (r == 9) {
        return true;
      }
      if (c == 9) {
        return self(self, r + 1, 0);
      }
      if (board[r][c] != '.') {
        return self(self, r, c + 1);
      }
      for (int i{1}; i <= 9; ++i) {
        if (rows[r][i] || cols[c][i] || boxes[r / 3][c / 3][i]) {
          continue;
        }
        rows[r][i] = cols[c][i] = boxes[r / 3][c / 3][i] = true;
        if (self(self, r, c + 1)) {
          board[r][c] = i + '0';
          return true;
        }
        rows[r][i] = cols[c][i] = boxes[r / 3][c / 3][i] = false;
      }
      return false;
    };
    dfs(dfs, 0, 0);
  }
};
