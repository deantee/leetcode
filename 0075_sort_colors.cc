#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int cnt[3]{};
    for (int x : nums) {
      ++cnt[x];
    }
    int offset{};
    for (int i{}; i < 3; ++i) {
      for (int j{}; j < cnt[i]; ++j) {
        nums[j + offset] = i;
      }
      offset += cnt[i];
    }
  }
};
