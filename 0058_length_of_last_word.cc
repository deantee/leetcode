#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int n(s.size()), m{};
    int i{n - 1};
    while (i >= 0 && s[i] == ' ') {
      --i;
    }
    for (; i >= 0 && s[i] != ' '; --i) {
      ++m;
    }
    return m;
  }
};
