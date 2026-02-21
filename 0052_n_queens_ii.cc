#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    int ans{};
    vector<bool> cs(n), ds0(n * 2 - 1), ds1(n * 2 - 1);
    auto dfs = [&](auto&& self, int r) -> void {
      if (r == n) {
        ++ans;
      }
      for (int c{}; c < n; ++c) {
        if (cs[c] || ds0[r + c] || ds1[r + (n - c - 1)]) {
          continue;
        }
        cs[c] = ds0[r + c] = ds1[r + (n - c - 1)] = true;
        self(self, r + 1);
        cs[c] = ds0[r + c] = ds1[r + (n - c - 1)] = false;
      }
    };
    dfs(dfs, 0);
    return ans;
  }
};
