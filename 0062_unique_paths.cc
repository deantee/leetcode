#include <bits/stdc++.h>

using namespace std;

static int choose(int n, int k) {
  long long ans{1};
  k = min(k, n - k);
  for (int i{1}; i <= k; ++i) {
    ans *= n - k + i;
    ans /= i;
  }
  return ans;
}

class Solution {
 public:
  int uniquePaths(int m, int n) { return choose(m + n - 2, n - 1); }
};
