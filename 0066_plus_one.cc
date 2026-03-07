#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int n(digits.size());
    int i{n};
    while (i-- && digits[i] == 9) {
      digits[i] = 0;
    }
    if (i == -1) {
      digits.emplace(digits.begin(), 1);
    } else {
      ++digits[i];
    }
    return digits;
  }
};
