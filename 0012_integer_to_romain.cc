#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    static const int a[] = {1000, 900, 500, 400, 100, 90, 50,
                            40,   10,  9,   5,   4,   1};
    static const string b[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                               "XL", "X",  "IX", "V",  "IV", "I"};
    string ans;
    for (int i{}; i < 13; ++i) {
      while (num >= a[i]) {
        num -= a[i];
        ans.append(b[i]);
      }
    }
    return ans;
  }
};
