#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
#endif

class Solution {
 public:
  int sumRootToLeaf(TreeNode* root) {
    int ans{};
    auto dfs = [&](auto&& self, TreeNode* root, int x) -> void {
      if (!root) {
        return;
      }
      x = x * 2 + root->val;
      if (!root->left && !root->right) {
        ans += x;
        return;
      }
      self(self, root->left, x);
      self(self, root->right, x);
    };
    dfs(dfs, root, 0);
    return ans;
  }
};
