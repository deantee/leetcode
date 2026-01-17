#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    static const array<string, 10> a{"",    "",    "abc",  "def", "ghi",
                                     "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    auto dfs = [&](auto&& self, int i, string& cur) -> void {
      if (i == int(digits.size())) {
        res.emplace_back(cur);
        return;
      }
      for (char ch : a[digits[i] - '0']) {
        cur.push_back(ch);
        self(self, i + 1, cur);
        cur.pop_back();
      }
    };
    string tmp;
    dfs(dfs, 0, tmp);
    return res;
  }
};
