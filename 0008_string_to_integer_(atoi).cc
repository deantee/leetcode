#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    int n(s.size());
    int i{};
    while (i < n && s[i] == ' ') {
      ++i;
    }
    if (i == n) {
      return 0;
    }
    bool neg{};
    if (s[i] == '+' || s[i] == '-') {
      neg = s[i] == '-';
      ++i;
    }
    int x{};
    while (i < n && s[i] >= '0' && s[i] <= '9') {
      int r{s[i] - '0'};
      if (x > INT_MAX / 10 || (x == INT_MAX / 10 && r > 7)) {
        return neg ? INT_MIN : INT_MAX;
      }
      x *= 10;
      x += r;
      ++i;
    }
    return x * (neg ? -1 : 1);
  }
};
