#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto& str : strs) {
      string cpy{str};
      sort(cpy.begin(), cpy.end());
      mp[cpy].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto& [k, v] : mp) {
      ans.emplace_back(v);
    }
    return ans;
  }
};
