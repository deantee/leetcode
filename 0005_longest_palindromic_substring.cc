#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string t{"^#"};
    for (char ch : s) {
      t.push_back(ch);
      t.push_back('#');
    }
    t.push_back('$');
    int m(t.size());
    vector<int> p(m);
    for (int i{1}, c{}, r{}; i < m - 1; ++i) {
      if (i < r) {
        p[i] = min(r - i, p[c * 2 - i]);
      }
      while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
        ++p[i];
      }
      if (i + p[i] > r) {
        c = i;
        r = i + p[i];
      }
    }
    int best{}, best_i{};
    for (int i{}; i < m; ++i) {
      if (best < p[i]) {
        best = p[i];
        best_i = i;
      }
    }
    return s.substr((best_i - best) / 2, best);
  }
};
