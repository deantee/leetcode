#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string ans{"1"};
    for (int i{1}; i < n; ++i) {
      string nxt{};
      int m(ans.size());
      int cnt{1};
      for (int j{1}; j < m; ++j) {
        if (ans[j] == ans[j - 1]) {
          ++cnt;
        } else {
          nxt += to_string(cnt);
          nxt += ans[j - 1];
          cnt = 1;
        }
      }
      nxt += to_string(cnt);
      nxt += ans[m - 1];
      ans = nxt;
    }
    return ans;
  }
};
