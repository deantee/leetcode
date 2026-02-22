#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans{INT_MIN}, s{};
    for (int x : nums) {
      s = max(x, s + x);
      ans = max(ans, s);
    }
    return ans;
  }
};
