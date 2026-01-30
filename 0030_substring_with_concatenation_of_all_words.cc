#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int n(s.size());
    int m(words.size());
    int len(words[0].size());
    unordered_map<string, int> cnt;
    for (auto& word : words) {
      ++cnt[word];
    }
    vector<int> ans;
    for (int off{}; off < len; ++off) {
      unordered_map<string, int> cur;
      int used{};
      for (int l{off}, r{off}; r + len <= n; r += len) {
        string word{s.substr(r, len)};
        if (!cnt.count(word)) {
          cur.clear();
          l = r + len;
          used = 0;
          continue;
        }
        while (cnt[word] == cur[word]) {
          --cur[s.substr(l, len)];
          l += len;
          --used;
        }
        ++cur[word];
        ++used;
        if (used == m) {
          --cur[s.substr(l, len)];
          ans.emplace_back(l);
          l += len;
          --used;
        }
      }
    }
    return ans;
  }
};
