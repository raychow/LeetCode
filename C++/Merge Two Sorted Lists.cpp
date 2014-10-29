class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
        {
            return l1 ? l1 : l2;
        }
        ListNode *head = new ListNode(0);
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        ListNode *cur = head;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                cur->next = h1;
                cur = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                cur = h2;
                h2 = h2->next;
            }
        }
        cur->next = h1 ? h1 : h2;
        ListNode *result = head->next;
        delete head;
        return result;
    }
};