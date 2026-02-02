#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n(nums.size());
    int l{}, r{n};
    while (l < r) {
      int m{l + (r - l) / 2};
      if (nums[0] > nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    int off{l};
    l = 0;
    r = n;
    while (l <= r) {
      int m{l + (r - l) / 2};
      int k{(m + off) % n};
      if (nums[k] == target) {
        return k;
      }
      if (nums[k] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return -1;
  }
};
