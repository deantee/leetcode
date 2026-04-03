#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int minimumPairRemoval(vector<int>& vec) {
    vector<ll> nums(vec.begin(), vec.end());
    int n(nums.size());
    vector<int> left(n), right(n);
    iota(left.begin(), left.end(), -1LL);
    iota(right.begin(), right.end(), 1LL);
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n_inv{};
    for (int i{1}; i < n; ++i) {
      pq.emplace(nums[i] + nums[i - 1], i);
      if (nums[i] < nums[i - 1]) {
        ++n_inv;
      }
    }
    int ans{};
    auto inv = [&](int i) -> int {
      return i > 0 && i < n && left[i] >= 0 && nums[i] < nums[left[i]];
    };
    while (n_inv > 0) {
      auto [sum, r] = pq.top();
      pq.pop();
      int l{left[r]};
      if (l < 0 || right[l] != r || nums[l] + nums[r] != sum) {
        continue;
      }
      n_inv -= inv(l) + inv(r) + inv(right[r]);
      left[r] = left[l];
      if (left[l] >= 0) {
        right[left[l]] = r;
      }
      left[l] = -1;
      nums[r] = sum;
      n_inv += inv(r) + inv(right[r]);
      if (left[r] >= 0) {
        pq.emplace(nums[r] + nums[left[r]], r);
      }
      if (right[r] < n) {
        pq.emplace(nums[right[r]] + nums[r], right[r]);
      }
      ++ans;
    }
    return ans;
  }
};
