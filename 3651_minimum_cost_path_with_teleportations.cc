#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid, int k) {
    int m(grid.size()), n(grid[0].size());
    int mx{0};
    for (int i{0}; i < m; ++i) {
      for (int j{0}; j < n; ++j) {
        mx = max(mx, grid[i][j]);
      }
    }

    long long const INF{(1LL << 60)};
    vector dp(k + 1, vector(m + 1, vector<long long>(n + 1, INF)));

    for (int t{0}; t <= k; ++t) {
      dp[t][0][1] = 0;
      dp[t][1][0] = 0;
      dp[t][1][1] = 0;  // start cell cost is 0
    }

    // t = 0: normal moves only (right/down), pay destination cell value
    for (int i{1}; i <= m; ++i) {
      for (int j{1}; j <= n; ++j) {
        if (i == 1 && j == 1)
          continue;
        dp[0][i][j] =
            min(dp[0][i - 1][j], dp[0][i][j - 1]) + grid[i - 1][j - 1];
      }
    }

    for (int t{1}; t <= k; ++t) {
      // bestAtVal[v] = min dp[t-1][i][j] among cells with grid[i][j] == v
      vector<long long> bestAtVal(mx + 2, INF);
      for (int i{1}; i <= m; ++i) {
        for (int j{1}; j <= n; ++j) {
          bestAtVal[grid[i - 1][j - 1]] =
              min(bestAtVal[grid[i - 1][j - 1]], dp[t - 1][i][j]);
        }
      }

      // suffix min: bestAtVal[v] becomes min dp[t-1] among cells with value >=
      // v
      for (int v{mx - 1}; v >= 0; --v) {
        bestAtVal[v] = min(bestAtVal[v], bestAtVal[v + 1]);
      }

      // Base for layer t: either don't use a new teleport, or use 1 teleport
      // from layer t-1
      for (int i{1}; i <= m; ++i) {
        for (int j{1}; j <= n; ++j) {
          dp[t][i][j] = min(dp[t - 1][i][j], bestAtVal[grid[i - 1][j - 1]]);
        }
      }
      dp[t][1][1] = 0;

      // Propagate normal moves within the same layer t
      for (int i{1}; i <= m; ++i) {
        for (int j{1}; j <= n; ++j) {
          if (i == 1 && j == 1)
            continue;
          dp[t][i][j] = min(dp[t][i][j], dp[t][i - 1][j] + grid[i - 1][j - 1]);
          dp[t][i][j] = min(dp[t][i][j], dp[t][i][j - 1] + grid[i - 1][j - 1]);
        }
      }
    }

    return (int)dp[k][m][n];
  }
};
