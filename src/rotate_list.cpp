#include "leetcode.h"

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;

    ListNode* tail = head;
    ListNode* new_tail = head;
    ListNode* new_head = nullptr;
    int N = 1;

    while (tail->next != nullptr) {
      tail = tail->next;
      N++;
    }

    k = N - k % N;
    if (k == N) return head;

    for (int i = 0; i < k - 1; i++) {
      new_tail = new_tail->next;
    }

    new_head = new_tail->next;
    new_tail->next = nullptr;
    tail->next = head;

    return new_head;
  }
};