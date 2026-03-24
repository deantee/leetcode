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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *ans{head}, *cur{head};
    while (head->next) {
      head = head->next;
      if (cur->val != head->val) {
        cur = cur->next = head;
      }
    }
    cur->next = nullptr;
    return ans;
  }
};
