#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans{nums[0] + nums[1] + nums[2]};
    int n(nums.size());
    for (int i{}; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j{i + 1};
      int k{n - 1};
      while (j < k) {
        int sum{nums[i] + nums[j] + nums[k]};
        if (abs(target - ans) > abs(target - sum)) {
          ans = sum;
        }
        if (sum == target) {
          return target;
        }
        if (sum < target) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return ans;
  }
};
