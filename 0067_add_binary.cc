#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int n(a.size()), m(b.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry{};
    string ans;
    for (int i{}; i < n || i < m || carry; ++i) {
      carry += (i < n ? a[i] - '0' : 0) + (i < m ? b[i] - '0' : 0);
      ans.push_back(carry % 2 + '0');
      carry /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
