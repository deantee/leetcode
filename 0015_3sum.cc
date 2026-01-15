#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n(nums.size());
    vector<vector<int>> ans;
    for (int i{}; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j{i + 1};
      int k{n - 1};
      while (j < k) {
        int sum{nums[i] + nums[j] + nums[k]};
        if (sum == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
        }
        if (sum <= 0) {
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
        }
        if (sum >= 0) {
          do {
            --k;
          } while (j < k && nums[k] == nums[k + 1]);
        }
      }
    }
    return ans;
  }
};
