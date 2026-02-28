#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector ans(n, vector<int>(n));
    int dx[]{0, 1, 0, -1};
    int dy[]{1, 0, -1, 0};
    int x{}, y{}, k{}, i{};
    while (x >= 0 && x < n && y >= 0 && y < n && ans[x][y] == 0) {
      ans[x][y] = ++i;
      int nx{x + dx[k]}, ny{y + dy[k]};
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || ans[nx][ny] > 0) {
        k = (k + 1) % 4;
      }
      x += dx[k];
      y += dy[k];
    }
    return ans;
  }
};
