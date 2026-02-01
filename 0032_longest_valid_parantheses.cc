#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n(s.size());
    int best{};
    for (int i{}, l{}, r{}; i < n; ++i) {
      if (s[i] == '(') {
        ++l;
      } else {
        ++r;
      }
      if (l == r) {
        best = max(best, r * 2);
      } else if (l < r) {
        l = r = 0;
      }
    }
    for (int i{n}, l{}, r{}; i--;) {
      if (s[i] == '(') {
        ++l;
      } else {
        ++r;
      }
      if (l == r) {
        best = max(best, l * 2);
      } else if (l > r) {
        l = r = 0;
      }
    }
    return best;
  }
};
