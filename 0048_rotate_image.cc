#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n(matrix.size());
    for (int i{}; i < n; ++i) {
      for (int j{i + 1}; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i{}; i < n; ++i) {
      for (int j{}; j < n / 2; ++j) {
        swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }
};
