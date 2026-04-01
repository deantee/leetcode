#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int n(nums.size());
    vector<int> ans(n);
    for (int i{}; i < n; ++i) {
      if (nums[i] == 2) {
        ans[i] = -1;
      } else {
        int k{__builtin_ctz(nums[i] + 1)};
        ans[i] = (nums[i] & ~((1 << k) - 1)) | ((1 << (k - 1)) - 1);
      }
    }
    return ans;
  }
};
