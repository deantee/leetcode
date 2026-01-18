#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n(nums.size());
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i{}; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] <
          target) {
        continue;
      }
      if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] >
          target) {
        break;
      }
      for (int j{i + 1}; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
          continue;
        }
        if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
          break;
        }
        int l{j + 1};
        int r{n - 1};
        while (l < r) {
          long long s{(long long)nums[i] + nums[j] + nums[l] + nums[r]};
          if (s == target) {
            ans.push_back({nums[i], nums[j], nums[l], nums[r]});
            do {
              ++l;
            } while (l < r && nums[l] == nums[l - 1]);
            do {
              --r;
            } while (l < r && nums[r] == nums[r + 1]);
          } else if (s < target) {
            ++l;
          } else {
            --r;
          }
        }
      }
    }
    return ans;
  }
};
