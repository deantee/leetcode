#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    int m(s.size()), n(t.size());
    if (m < n) {
      return "";
    }
    int req[256]{};
    int req_n{};
    for (char c : t) {
      if (++req[(unsigned char)c] == 1) {
        ++req_n;
      }
    }
    int cnt[256]{};
    int best_l{-1}, best_len{INT_MAX};
    for (int l{}, r{}; r < m; ++r) {
      if (++cnt[(unsigned char)s[r]] == req[(unsigned char)s[r]]) {
        --req_n;
      }
      while (l < r && (req[(unsigned char)s[l]] == 0 ||
                       cnt[(unsigned char)s[l]] > req[(unsigned char)s[l]])) {
        --cnt[(unsigned char)s[l++]];
      }
      if (req_n == 0) {
        int len{r - l + 1};
        if (best_len > len) {
          best_len = len;
          best_l = l;
        }
      }
    }
    if (best_l == -1) {
      return "";
    }
    return s.substr(best_l, best_len);
  }
};
