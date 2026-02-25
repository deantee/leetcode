#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.reserve(intervals.size());
    vector<int> cur{intervals[0]};
    int n(intervals.size());
    for (int i{1}; i < n; ++i) {
      if (intervals[i][0] <= cur[1]) {
        cur[1] = max(cur[1], intervals[i][1]);
      } else {
        ans.emplace_back(cur);
        cur = intervals[i];
      }
    }
    ans.emplace_back(cur);
    return ans;
  }
};
