#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> buf;
    buf.reserve(k);
    auto dfs = [&](auto&& self, int i) -> void {
      if (i == k) {
        ans.emplace_back(buf);
        return;
      }
      for (int j{buf.empty() ? 1 : buf.back() + 1}; j <= n; ++j) {
        buf.emplace_back(j);
        self(self, i + 1);
        buf.pop_back();
      }
    };
    dfs(dfs, 0);
    return ans;
  }
};
