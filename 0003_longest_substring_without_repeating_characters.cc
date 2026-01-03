#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n(s.size());
    if (n < 2) {
      return n;
    }
    array<int, 256> last;
    last.fill(-1);
    int ans{1};
    for (int l{}, r{}; r < n; ++r) {
      l = max(l, last[s[r]] + 1);
      last[s[r]] = r;
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
