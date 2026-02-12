#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    int n(num1.size()), m(num2.size());
    vector<int> res(n + m);
    for (int i{}; i < n; ++i) {
      if (num1[i] == '0') {
        continue;
      }
      for (int j{}; j < m; ++j) {
        res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    for (int i{n + m}; i-- > 1;) {
      res[i - 1] += res[i] / 10;
      res[i] %= 10;
    }
    string ans;
    for (int i{res[0] ? 0 : 1}; i < n + m; ++i) {
      ans += res[i] + '0';
    }
    return ans;
  }
};
