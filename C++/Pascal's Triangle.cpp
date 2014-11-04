class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        if (numRows <= 0)
        {
            return result;
        }
        result.push_back(vector < int > {1});
        --numRows;
        while (numRows--)
        {
            vector<int> row;
            row.push_back(1);
            auto last_result = result.back();
            for (int i = 0; i < last_result.size() - 1; ++i)
            {
                row.push_back(last_result[i] + last_result[i + 1]);
            }
            row.push_back(1);
            result.push_back(move(row));
        }
        return result;
    }
};
