class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        auto *dummy = new ListNode(0);
        auto *cur = head;
        while (cur)
        {
            auto *ins = dummy;
            while (ins->next && ins->next->val < cur->val)
            {
                ins = ins->next;
            }
            auto *tmp = ins->next;
            ins->next = cur;
            cur = cur->next;
            ins->next->next = tmp;
        }
        return dummy->next;
    }
};
