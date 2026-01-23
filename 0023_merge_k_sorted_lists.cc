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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto compar = [](const ListNode* a, const ListNode* b) -> bool {
      return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compar)> pq(compar);
    for (auto& list : lists) {
      if (list) {
        pq.emplace(list);
      }
    }
    ListNode* dummy{new ListNode};
    ListNode* t{dummy};
    while (!pq.empty()) {
      t = t->next = pq.top();
      pq.pop();
      if (t->next) {
        pq.emplace(t->next);
      }
    }
    t = dummy->next;
    delete dummy;
    return t;
  }
};
