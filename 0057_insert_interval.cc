#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    intervals.insert(
        lower_bound(intervals.begin(), intervals.end(), newInterval),
        newInterval);
    vector<int> cur{intervals[0]};
    vector<vector<int>> ans;
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
