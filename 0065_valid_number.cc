#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    int n(s.size());
    int i{};
    bool f0{}, f1{};
    if (s[i] == '-' || s[i] == '+') {
      ++i;
    }
    if (i == n) {
      return false;
    }
    while (i < n && isdigit(s[i])) {
      ++i;
      f0 = true;
    }
    if (i == n) {
      return true;
    }
    if (s[i] == '.') {
      ++i;
    }
    while (i < n && isdigit(s[i])) {
      ++i;
      f1 = true;
    }
    if (!f0 && !f1) {
      return false;
    }
    if (i == n) {
      return true;
    }
    if (s[i] != 'e' && s[i] != 'E') {
      return false;
    }
    ++i;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
      ++i;
    }
    if (i == n) {
      return false;
    }
    while (i < n && isdigit(s[i])) {
      ++i;
    }
    return i == n;
  }
};
