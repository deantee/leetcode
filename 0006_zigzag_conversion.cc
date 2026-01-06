#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int n(s.size());
    string ans;
    ans.reserve(n);
    for (int i = 0; i < n; i += numRows * 2 - 2) {
      ans.push_back(s[i]);
    }
    for (int i = 1; i < numRows - 1; ++i) {
      for (int j = i; j < n; j += numRows * 2 - 2) {
        ans.push_back(s[j]);
        if (j + numRows * 2 - 2 - i * 2 < n) {
          ans.push_back(s[j + numRows * 2 - 2 - i * 2]);
        }
      }
    }
    for (int i = numRows - 1; i < n; i += numRows * 2 - 2) {
      ans.push_back(s[i]);
    }
    return ans;
  }
};
