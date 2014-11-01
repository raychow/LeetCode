class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *left = new ListNode(0);
        ListNode *leftBack = left;
        ListNode *right = new ListNode(0);
        ListNode *rightBack = right;
        while (head)
        {
            if (head->val < x)
            {
                leftBack->next = head;
                leftBack = leftBack->next;
            }
            else
            {
                rightBack->next = head;
                rightBack = rightBack->next;
            }
            head = head->next;
        }
        leftBack->next = right->next;
        rightBack->next = NULL;
        ListNode *result = left->next;
        delete left;
        delete right;
        return result;
    }
};
