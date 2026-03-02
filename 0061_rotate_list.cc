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
  ListNode* rotateRight(ListNode* head, int k) {
    ListNode* a{head};
    int n{};
    ListNode* last{nullptr};
    while (a) {
      last = a;
      a = a->next;
      ++n;
    }
    if (n < 2) {
      return head;
    }
    k %= n;
    if (k == 0) {
      return head;
    }
    a = head;
    ListNode* b{head};
    for (int i{}; i < k; ++i) {
      b = b->next;
    }
    while (b->next) {
      a = a->next;
      b = b->next;
    }
    ListNode* newHead{a->next};
    a->next = nullptr;
    last->next = head;
    return newHead;
  }
};
