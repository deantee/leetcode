#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n{INT_MAX};
    for (auto& s : strs) {
      n = min(n, int(s.size()));
    }
    for (int i = 0; i < n; ++i) {
      char ch{strs[0][i]};
      for (auto& s : strs) {
        if (s[i] != ch) {
          return s.substr(0, i);
        }
      }
    }
    return strs[0].substr(0, n);
  }
};
