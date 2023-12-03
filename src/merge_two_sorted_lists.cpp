#include "leetcode.h"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head;
    ListNode* list = &head;

    while (list1 != nullptr || list2 != nullptr) {
      if (list2 == nullptr || list1 != nullptr && list1->val <= list2->val) {
        list->next = list1;
        list1 = list1->next;
      } else {
        list->next = list2;
        list2 = list2->next;
      }
      list = list->next;
      list->next = nullptr;
    }

    return head.next;
  }
};