#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto [l, r] = equal_range(nums.begin(), nums.end(), target);
    return l == nums.end() || *l != target
               ? vector{-1, -1}
               : vector{int(l - nums.begin()), int(r - nums.begin() - 1)};
  }
};
