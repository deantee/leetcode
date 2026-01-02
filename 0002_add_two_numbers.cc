#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *t0 = new ListNode, *t1 = t0;
    int carry{};
    while (l1 || l2 || carry) {
      carry = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
      t1 = t1->next = new ListNode(carry % 10);
      carry /= 10;
    }
    t1 = t0->next;
    delete t0;
    return t1;
  }
};
