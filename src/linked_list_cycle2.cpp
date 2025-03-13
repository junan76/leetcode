#include "leetcode.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *cycle_start = nullptr;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cycle_start = slow;
                break;
            }
        }

        if (cycle_start == nullptr)
            return nullptr;
        cycle_start = head;
        while (cycle_start != slow)
        {
            cycle_start = cycle_start->next;
            slow = slow->next;
        }

        return cycle_start;
    }
};