#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m(matrix.size()), n(matrix[0].size());
    int l{}, r{m};
    while (l < r) {
      int mid{l + (r - l) / 2};
      if (matrix[mid][n - 1] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    int row{l};
    if (row >= m) {
      return false;
    }
    l = 0;
    r = n;
    while (l < r) {
      int mid{l + (r - l) / 2};
      if (matrix[row][mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    int col{l};
    if (col >= n) {
      return false;
    }
    return matrix[row][col] == target;
  }
};
