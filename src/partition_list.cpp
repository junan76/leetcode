#include "leetcode.h"

/**
 * 分隔链表.
 * NOTE: 增加一个guard节点, 统一了链表的操作. 找到第一个大于等于x的节点,
 * 之后以此为开始, 遍历剩下的节点, 把所有小于x的节点都插入到节点i的前面.
 */
class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    ListNode guard{0, head};

    ListNode *iprev, *i, *inext;
    ListNode *jprev, *j, *jnext;

    iprev = &guard;
    i = iprev->next;
    inext = i != nullptr ? i->next : nullptr;

    while (i != nullptr && i->val < x) {
      iprev = i;
      i = inext;
      inext = i != nullptr ? i->next : nullptr;
    }

    jprev = iprev;
    j = i;
    jnext = inext;

    while (j != nullptr) {
      while (j != nullptr && j->val >= x) {
        jprev = j;
        j = jnext;
        jnext = j != nullptr ? j->next : nullptr;
      }

      if (j != nullptr) {
        jprev->next = jnext;

        iprev->next = j;
        j->next = i;
        iprev = j;

        j = jnext;
        jnext = j != nullptr ? j->next : nullptr;
      }
    }

    return guard.next;
  }
};
