class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return __getDepth(root) != -1;
    }

private:
    int __getDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int leftDepth = __getDepth(root->left);
        if (-1 == leftDepth)
        {
            return -1;
        }
        int rightDepth = __getDepth(root->right);
        if (-1 == rightDepth || abs(leftDepth - rightDepth) > 1)
        {
            return -1;
        }
        return max(leftDepth, rightDepth) + 1;
    }
};
