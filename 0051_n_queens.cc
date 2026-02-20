#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> buf(n, string(n, '.'));
    vector<uint8_t> cs(n), ds0(n * 2 - 1), ds1(n * 2 - 1);
    auto dfs = [&](auto&& self, int r) -> void {
      if (r == n) {
        ans.emplace_back(buf);
        return;
      }
      for (int c{}; c < n; ++c) {
        if (cs[c] || ds0[r + c] || ds1[r + (n - c - 1)]) {
          continue;
        }
        cs[c] = ds0[r + c] = ds1[r + (n - c - 1)] = true;
        buf[r][c] = 'Q';
        self(self, r + 1);
        cs[c] = ds0[r + c] = ds1[r + (n - c - 1)] = false;
        buf[r][c] = '.';
      }
    };
    dfs(dfs, 0);
    return ans;
  }
};
