#include "leetcode.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode guard(0, head);
        ListNode *prev = &guard;
        ListNode *first = head;
        ListNode *second = head != nullptr ? head->next : nullptr;

        while (first != nullptr && second != nullptr)
        {
            first->next = second->next;
            prev->next = second;
            second->next = first;

            prev = first;
            first = prev->next;
            second = first != nullptr ? first->next : nullptr;
        }
        return guard.next;
    }
};