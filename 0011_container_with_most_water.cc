#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n(height.size());
    int i{}, j{n - 1};
    int ans{};
    while (i < j) {
      ans = max(ans, (j - i) * min(height[i], height[j]));
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return ans;
  }
};
