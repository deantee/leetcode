#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n(s.size()), m(p.size()), i{}, j{}, pi{}, pj{-1};
    while (i < n) {
      if (j < m && (s[i] == p[j] || p[j] == '?')) {
        ++i;
        ++j;
      } else if (j < m && p[j] == '*') {
        pi = i;
        pj = j++;
      } else if (pj != -1) {
        i = ++pi;
        j = pj + 1;
      } else {
        return false;
      }
    }
    while (j < m && p[j] == '*') {
      ++j;
    }
    return j == m;
  }
};
