class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        if (rowIndex < 0)
        {
            return result;
        }
        result.resize(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        for (int i = 1; i <= rowIndex / 2; ++i)
        {
            result[i] = result[rowIndex - i]
                = (long long int)result[i - 1] * (rowIndex - i + 1) / i;
        }
        return result;
    }
};
