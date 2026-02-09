#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int n(candidates.size());
    vector<vector<int>> ans;
    auto dfs = [&](auto&& self, vector<int>& buf, int target, int i) -> void {
      if (target == 0) {
        ans.emplace_back(buf);
        return;
      }
      for (int j{i}; j < n; ++j) {
        if (j > i && candidates[j] == candidates[j - 1]) {
          continue;
        }
        if (target < candidates[j]) {
          break;
        }
        buf.emplace_back(candidates[j]);
        self(self, buf, target - candidates[j], j + 1);
        buf.pop_back();
      }
    };
    vector<int> buf;
    dfs(dfs, buf, target, 0);
    return ans;
  }
};
