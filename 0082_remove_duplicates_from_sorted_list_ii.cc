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
    int prev{head->val};
    vector<int> vec{prev};
    while (head->next) {
      head = head->next;
      if (prev == head->val) {
        if (!vec.empty() && vec.back() == prev) {
          vec.pop_back();
        }
      } else {
        prev = head->val;
        vec.emplace_back(prev);
      }
    }
    ListNode* dummy{new ListNode};
    ListNode* cur{dummy};
    for (int x : vec) {
      cur = cur->next = new ListNode(x);
    }
    cur = dummy->next;
    delete dummy;
    return cur;
  }
};
