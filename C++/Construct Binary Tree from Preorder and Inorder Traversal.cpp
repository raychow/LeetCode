class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        size_t preIndex = 0;
        return __buildTree(preorder, preIndex, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *__buildTree(
        vector<int> &preorder, size_t &preIndex, vector<int> &inorder, int inLow, int inHigh)
    {
        if (preIndex >= preorder.size() || inLow > inHigh)
        {
            return nullptr;
        }
        TreeNode *result = new TreeNode(preorder[preIndex]);
        int inRoot = find(inorder.begin() + inLow, inorder.begin() + inHigh + 1,
            preorder[preIndex]) - inorder.begin();
        ++preIndex;
        result->left = __buildTree(preorder, preIndex, inorder, inLow, inRoot - 1);
        result->right = __buildTree(preorder, preIndex, inorder, inRoot + 1, inHigh);
        return result;
    }
};
