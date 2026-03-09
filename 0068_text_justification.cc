#include <bits/stdc++.h>

using namespace std;

static string justify(const vector<string>& buf, int len, int maxWidth) {
  if (buf.size() == 1) {
    return buf[0] + string(maxWidth - buf[0].size(), ' ');
  }
  string ans;
  int gap{(maxWidth - len) / int(buf.size() - 1)};
  int n(buf.size()), m(maxWidth - len - (buf.size() - 1) * gap);
  ans += buf[0];
  for (int i{1}; i < n; ++i) {
    ans.append(gap + (i <= m), ' ');
    ans += buf[i];
  }
  return ans;
}

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans, buf;
    vector<int> lens;
    vector<vector<string>> bufs;
    int len{};
    for (auto& word : words) {
      if (len + int(buf.size() + word.size()) > maxWidth) {
        bufs.emplace_back(buf);
        lens.emplace_back(len);
        buf.clear();
        len = 0;
      }
      buf.emplace_back(word);
      len += word.size();
    }
    if (len) {
      bufs.emplace_back(buf);
      lens.emplace_back(len);
    }
    for (int i{}; i < int(bufs.size()) - 1; ++i) {
      ans.emplace_back(justify(bufs[i], lens[i], maxWidth));
    }
    string t;
    for (auto& word : bufs.back()) {
      t += word + ' ';
    }
    t.pop_back();
    t.append(maxWidth - t.size(), ' ');
    ans.emplace_back(t);
    return ans;
  }
};
