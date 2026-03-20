#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m(board.size()), n(board[0].size());
    int dd[]{-1, 0, 1, 0, -1};
    auto dfs = [&](auto&& self, int x, int y, int i) -> bool {
      if (i == int(word.size())) {
        return true;
      }
      for (int k{}; k < 4; ++k) {
        int nx{x + dd[k]}, ny{y + dd[k + 1]};
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            word[i] == board[nx][ny]) {
          char prev{board[nx][ny]};
          board[nx][ny] = '#';
          if (self(self, nx, ny, i + 1)) {
            return true;
          }
          board[nx][ny] = prev;
        }
      }
      return false;
    };
    for (int i{}; i < m; ++i) {
      for (int j{}; j < n; ++j) {
        if (board[i][j] == word[0]) {
          board[i][j] = '#';
          if (dfs(dfs, i, j, 1)) {
            return true;
          }
          board[i][j] = word[0];
        }
      }
    }
    return false;
  }
};
