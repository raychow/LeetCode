class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return __sortedArrayToBST(num, 0, num.size() - 1);
    }

private:
    TreeNode *__sortedArrayToBST(vector<int> &num, int low, int high)
    {
        if (low > high)
        {
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode *result = new TreeNode(num[mid]);
        result->left = __sortedArrayToBST(num, low, mid - 1);
        result->right = __sortedArrayToBST(num, mid + 1, high);
        return result;
    }
};
