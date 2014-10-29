class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }
        int i = 0;
        int j = matrix[0].size() - 1;
        int m = matrix.size();
        while (i < m && j >= 0)
        {
            int value = matrix[i][j];
            if (value > target)
            {
                --j;
            }
            else if (value < target)
            {
                ++i;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};