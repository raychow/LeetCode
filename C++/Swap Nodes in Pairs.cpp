class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;
        while (current && current->next)
        {
            prev->next = current->next;
            ListNode *tmp = current->next->next;
            current->next->next = current;
            current->next = tmp;
            prev = current;
            current = tmp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
