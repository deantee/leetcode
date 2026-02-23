#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n(matrix.size()), m(matrix[0].size()), sz{n * m};
    array<int, 4> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
    int x{}, y{};
    vector used(n, vector<bool>(m));
    vector<int> ans;
    ans.reserve(sz);
    ans.emplace_back(matrix[0][0]);
    used[0][0] = true;
    for (int i{1}, k{}; i < sz; ++i) {
      int nx{x + dx[k]}, ny{y + dy[k]};
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny]) {
        k = (k + 1) % 4;
        nx = x + dx[k];
        ny = y + dy[k];
      }
      x = nx;
      y = ny;
      ans.emplace_back(matrix[x][y]);
      used[x][y] = true;
    }
    return ans;
  }
};
