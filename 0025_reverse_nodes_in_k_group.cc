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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* t{head};
    for (int i{}; i < k; ++i) {
      if (!t) {
        return head;
      }
      t = t->next;
    }
    ListNode* last{reverseKGroup(t, k)};
    ListNode* dummy{new ListNode};
    t = head;
    for (int i{}; i < k; ++i) {
      ListNode* nxt{t->next};
      t->next = dummy->next;
      dummy->next = t;
      t = nxt;
    }
    head->next = last;
    t = dummy->next;
    delete dummy;
    return t;
  }
};
