#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n(nums.size()), ans{}, last{}, lim{};
    for (int i{}; i < n; ++i) {
      if (i > last) {
        ++ans;
        last = lim;
      }
      lim = max(lim, i + nums[i]);
    }
    return ans;
  }
};
