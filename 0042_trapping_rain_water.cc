#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int n(height.size());
    vector<int> l(n), r(n);
    l[0] = height[0];
    r[n - 1] = height[n - 1];
    for (int i{1}; i < n; ++i) {
      l[i] = max(l[i - 1], height[i]);
      r[n - i - 1] = max(r[n - i], height[n - i - 1]);
    }
    int ans{};
    for (int i{}; i < n; ++i) {
      ans += min(l[i], r[i]) - height[i];
    }
    return ans;
  }
};
