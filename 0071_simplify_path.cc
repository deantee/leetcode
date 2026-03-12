#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    if (path.back() != '/') {
      path.push_back('/');
    }
    vector<string> stk;
    int i{}, ni;
    while ((ni = path.find('/', i + 1)) != int(string::npos)) {
      string s{path.substr(i + 1, ni - i - 1)};
      if (s == ".") {
      } else if (s == "..") {
        if (!stk.empty()) {
          stk.pop_back();
        }
      } else if (s.size()) {
        stk.emplace_back(s);
      }
      i = ni;
    }
    if (stk.empty()) {
      return "/";
    } else {
      string ans;
      for (auto& s : stk) {
        ans += "/" + s;
      }
      return ans;
    }
  }
};
