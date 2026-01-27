#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int n{};
    for (int x : nums) {
      if (x != val) {
        nums[n++] = x;
      }
    }
    return n;
  }
};
