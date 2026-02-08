#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n(candidates.size());
    vector<vector<int>> ans;
    auto dfs = [&](auto&& self, vector<int>& buf, int target, int i) -> void {
      if (i == n) {
        if (target == 0) {
          ans.emplace_back(buf);
        }
        return;
      }
      self(self, buf, target, i + 1);
      if (target >= candidates[i]) {
        buf.emplace_back(candidates[i]);
        self(self, buf, target - candidates[i], i);
        buf.pop_back();
      }
    };
    vector<int> buf;
    dfs(dfs, buf, target, 0);
    return ans;
  }
};
