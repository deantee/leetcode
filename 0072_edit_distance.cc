#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n(word1.size()), m(word2.size());
    vector dp(n + 1, vector<int>(m + 1));
    for (int i{1}; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i{1}; i <= m; ++i) {
      dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i{1}; i <= n; ++i) {
      for (int j{1}; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
        }
      }
    }
    return dp[n][m];
  }
};
