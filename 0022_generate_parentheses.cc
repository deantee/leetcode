#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string tmp;
    auto dfs = [&](auto&& self, int l, int r) -> void {
      if (r == 0) {
        ans.emplace_back(tmp);
        return;
      }
      if (l > 0) {
        tmp.push_back('(');
        self(self, l - 1, r);
        tmp.pop_back();
      }
      if (l < r) {
        tmp.push_back(')');
        self(self, l, r - 1);
        tmp.pop_back();
      }
    };
    dfs(dfs, n, n);
    return ans;
  }
};
