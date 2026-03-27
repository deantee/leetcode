#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int binaryGap(int n) {
    int last{-1};
    int ans{};
    for (int i{}; n; ++i) {
      if (n % 2) {
        if (last >= 0) {
          ans = max(ans, i - last);
        }
        last = i;
      }
      n /= 2;
    }
    return ans;
  }
};
