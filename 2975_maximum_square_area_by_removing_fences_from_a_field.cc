#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximizeSquareArea(int m,
                         int n,
                         vector<int>& hFences,
                         vector<int>& vFences) {
    hFences.emplace_back(1);
    hFences.emplace_back(m);
    vFences.emplace_back(1);
    vFences.emplace_back(n);
    int nh(hFences.size()), nv(vFences.size());
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());
    unordered_set<int> st;
    for (int i{}; i < nh; ++i) {
      for (int j{i + 1}; j < nh; ++j) {
        st.insert(hFences[j] - hFences[i]);
      }
    }
    int ans{-1};
    for (int i{}; i < nv; ++i) {
      for (int j{i + 1}; j < nv; ++j) {
        int x{vFences[j] - vFences[i]};
        auto it = st.find(x);
        if (it != st.end()) {
          if (ans == -1 || ans < x) {
            ans = x;
          }
        }
      }
    }
    return ans == -1 ? -1 : (long long)ans * ans % int(1e9 + 7);
  }
};
