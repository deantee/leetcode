#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0) {
      if (n == INT_MIN) {
        return abs(x) > 1 ? 0 : abs(x) == 1 ? 1 : INFINITY;
      }
      n = -n;
      x = 1 / x;
    }
    if (n == 0) {
      return 1;
    }
    double y{1};
    while (n) {
      if (n % 2) {
        y *= x;
      }
      x *= x;
      n /= 2;
    }
    return y;
  }
};
