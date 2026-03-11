#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n < 2) {
      return 1;
    }
    int a{1}, b{1};
    while (n-- > 1) {
      int c{a + b};
      a = b;
      b = c;
    }
    return b;
  }
};
