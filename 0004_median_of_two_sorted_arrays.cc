#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n(nums1.size()), m(nums2.size());
    auto solve = [&](auto&& self, int i, int j, int k) -> int {
      if (i >= n) {
        return nums2[j + k - 1];
      }
      if (j >= m) {
        return nums1[i + k - 1];
      }
      if (k == 1) {
        return min(nums1[i], nums2[j]);
      }
      int l{k / 2};
      return (i + l - 1 < n ? nums1[i + l - 1] : INT_MAX) <=
                     (j + l - 1 < m ? nums2[j + l - 1] : INT_MAX)
                 ? self(self, i + l, j, k - l)
                 : self(self, i, j + l, k - l);
    };
    return (solve(solve, 0, 0, (n + m + 1) / 2) +
            solve(solve, 0, 0, (n + m) / 2 + 1)) /
           2.0;
  }
};
