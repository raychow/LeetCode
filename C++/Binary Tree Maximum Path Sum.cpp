class Solution {
public:
    int maxPathSum(TreeNode *root) {
        unordered_map<TreeNode *, int> umMaxSum;
        int result = numeric_limits<int>::min();
        visit(root, umMaxSum, result);
        return result;
    }

private:
    int visit(TreeNode *root, unordered_map<TreeNode *, int> &umMaxSum, int &result)
    {
        if (!root)
        {
            return 0;
        }
        int nLeftMaxSum = max(visit(root->left, umMaxSum, result), 0);
        int nRightMaxSum = max(visit(root->right, umMaxSum, result), 0);
        result = max(result, nLeftMaxSum + nRightMaxSum + root->val);
        return umMaxSum[root] = max(nLeftMaxSum, nRightMaxSum) + root->val;
    }
};
