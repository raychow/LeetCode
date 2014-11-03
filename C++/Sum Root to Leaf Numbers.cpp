class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return __sumNumbers(root, 0);
    }

private:
    int __sumNumbers(TreeNode *root, int val)
    {
        if (!root)
        {
            return 0;
        }
        val *= 10;
        val += root->val;
        if (root->left || root->right)
        {
            return __sumNumbers(root->left, val)
                + __sumNumbers(root->right, val);
        }
        else
        {
            return val;
        }
    }
};
