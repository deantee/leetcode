#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n(nums.size());
    int lim{};
    for (int i{}; i < n; ++i) {
      if (i > lim) {
        return false;
      }
      lim = max(lim, i + nums[i]);
    }
    return true;
  }
};
