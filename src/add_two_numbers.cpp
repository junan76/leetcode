
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        int s = 0;
        int c = 0;
        ListNode *a = l1;
        ListNode *b = l2;

        while (a != nullptr || b != nullptr)
        {
            s += c;
            s += a != nullptr ? a->val : 0;
            s += b != nullptr ? b->val : 0;

            c = s / 10;
            s %= 10;
            append(&head, &tail, s);

            s = 0;
            a = a != nullptr ? a->next : nullptr;
            b = b != nullptr ? b->next : nullptr;
        }

        /* NOTE: 这里比较容易忽略, 最后进位不为0 */
        if (c != 0)
            append(&head, &tail, c);

        return head;
    }

    void append(ListNode **head, ListNode **tail, int n)
    {
        if (*head == *tail && *head == nullptr)
        {
            *head = new ListNode(n);
            *tail = *head;
            return;
        }
        else
        {
            (*tail)->next = new ListNode(n);
            *tail = (*tail)->next;
        }
    }
};