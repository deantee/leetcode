#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n(heights.size());
    vector<int> l(n), r(n);
    vector<int> stk;
    for (int i{}; i < n; ++i) {
      while (!stk.empty() && heights[stk.back()] >= heights[i]) {
        stk.pop_back();
      }
      l[i] = stk.empty() ? -1 : stk.back();
      stk.emplace_back(i);
    }
    stk.clear();
    for (int i{n}; i--;) {
      while (!stk.empty() && heights[stk.back()] >= heights[i]) {
        stk.pop_back();
      }
      r[i] = stk.empty() ? n : stk.back();
      stk.emplace_back(i);
    }
    int ans{};
    for (int i{}; i < n; ++i) {
      ans = max(ans, heights[i] * (r[i] - l[i] - 1));
    }
    return ans;
  }
};
