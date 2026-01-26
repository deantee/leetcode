#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n(nums.size()), m{};
    for (int i{1}; i < n; ++i) {
      if (nums[m] != nums[i]) {
        nums[++m] = nums[i];
      }
    }
    return m + 1;
  }
};
