#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n(nums.size());
    vector<vector<int>> ans;
    for (int i{}; i < 1 << n; ++i) {
      vector<int> buf;
      for (int j{}; j < n; ++j) {
        if (i >> j & 1) {
          buf.emplace_back(nums[j]);
        }
      }
      ans.emplace_back(buf);
    }
    return ans;
  }
};
