#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m(mat.size()), n(mat[0].size());
    int pf[301][301]{};
    for (int i{}; i < m; ++i) {
      for (int j{}, row{}; j < n; ++j) {
        row += mat[i][j];
        pf[i + 1][j + 1] = row + pf[i][j + 1];
      }
    }
    auto ok = [&](int k) -> bool {
      for (int i{k}; i <= m; ++i) {
        for (int j{k}; j <= n; ++j) {
          if (pf[i][j] - pf[i][j - k] - pf[i - k][j] + pf[i - k][j - k] <=
              threshold) {
            return true;
          }
        }
      }
      return false;
    };
    int lo{};
    int hi{min(m, n)};
    while (lo < hi) {
      int mid{lo + (hi - lo + 1) / 2};
      if (ok(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }
};
