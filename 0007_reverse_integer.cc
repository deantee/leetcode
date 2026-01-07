#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int ans{};
    while (x) {
      int r{x % 10};
      if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && r > 7) ||
          ans < INT_MIN / 10 || (ans == INT_MIN / 10 && r < -7)) {
        return 0;
      }
      ans *= 10;
      ans += r;
      x /= 10;
    }
    return ans;
  }
};
