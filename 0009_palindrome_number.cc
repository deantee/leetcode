#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }
    if (x > 0 && x % 10 == 0) {
      return false;
    }
    int y{};
    while (x > y) {
      y *= 10;
      y += x % 10;
      x /= 10;
    }
    return x == y || x == y / 10;
  }
};
