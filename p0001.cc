#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n(nums.size());
    unordered_map<int, int> mp;
    for (int i{}; i < n; ++i) {
      auto it = mp.find(nums[i]);
      if (it != mp.end()) {
        return {it->second, i};
      }
      mp[target - nums[i]] = i;
    }
    return {};
  }
};
