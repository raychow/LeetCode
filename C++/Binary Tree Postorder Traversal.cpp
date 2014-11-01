class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        __visit(root, result);
        return result;
    }

private:
    void __visit(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        __visit(root->left, result);
        __visit(root->right, result);
        result.push_back(root->val);
    }
};
