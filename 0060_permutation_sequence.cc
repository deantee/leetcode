#include <bits/stdc++.h>

using namespace std;

static int fact[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
 public:
  string getPermutation(int n, int k) {
    --k;
    string ans(n, 0);
    iota(ans.begin(), ans.end(), '1');
    int i{};
    while (i < n) {
      int j{n - i - 1};
      swap(ans[i], ans[i + k / fact[j]]);
      sort(ans.begin() + i + 1, ans.end());
      k %= fact[j];
      ++i;
    }
    return ans;
  }
};
