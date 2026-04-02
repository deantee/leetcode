#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimumPairRemoval(vector<int>& nums) {
    int n(nums.size());
    int old_n{n};
    for (;;) {
      bool bl{true};
      for (int i{1}; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
          bl = false;
          break;
        }
      }
      if (bl) {
        break;
      }
      int i{1};
      int min_sum{INT_MAX};
      for (int j{1}; j < n; ++j) {
        int sum{nums[j] + nums[j - 1]};
        if (min_sum > sum) {
          min_sum = sum;
          i = j;
        }
      }
      nums[i - 1] += nums[i];
      nums.erase(nums.begin() + i);
      --n;
    }
    return old_n - n;
  }
};
