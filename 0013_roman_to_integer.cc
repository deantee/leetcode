#include <bits/stdc++.h>

using namespace std;

static constexpr array<int, 256> get_table() {
  array<int, 1 << CHAR_BIT> arr{};
  arr['I'] = 1;
  arr['V'] = 5;
  arr['X'] = 10;
  arr['L'] = 50;
  arr['C'] = 100;
  arr['D'] = 500;
  arr['M'] = 1000;
  return arr;
};

static const constinit auto table = get_table();

class Solution {
 public:
  int romanToInt(string s) {
    int n(s.size());
    int ans{table[s.back()]};
    for (int i{n - 1}; i-- > 0;) {
      if (table[s[i]] < table[s[i + 1]]) {
        ans -= table[s[i]];
      } else {
        ans += table[s[i]];
      }
    }
    return ans;
  }
};
