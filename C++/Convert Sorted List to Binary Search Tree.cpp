class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        auto *node = head;
        int n = 0;
        while (node)
        {
            ++n;
            node = node->next;
        }
        return __sortedListToBST(head, 0, n - 1);
    }

private:
    TreeNode *__sortedListToBST(ListNode *&head, int low, int high)
    {
        if (low > high)
        {
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        auto left = __sortedListToBST(head, low, mid - 1);
        auto result = new TreeNode(head->val);
        head = head->next;
        result->left = left;
        result->right = __sortedListToBST(head, mid + 1, high);
        return result;
    }
};
