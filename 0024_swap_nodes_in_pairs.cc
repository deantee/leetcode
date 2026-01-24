#include <bits/stdc++.h>

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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* nxt = head->next;
    head->next = swapPairs(head->next->next);
    nxt->next = head;
    return nxt;
  }
};
