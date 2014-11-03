class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        if (n < 1 || k < 1)
        {
            return result;
        }
        vector<int> indexes;
        for (int i = 1; i <= k; ++i)
        {
            indexes.push_back(i);
        }
        while (true)
        {
            result.push_back(indexes);
            if (++indexes.back() > n)
            {
                while (!indexes.empty() && indexes.back() >= n - k + indexes.size())
                {
                    indexes.pop_back();
                }
                if (indexes.empty())
                {
                    break;
                }
                ++indexes.back();
                while (indexes.size() < k)
                {
                    indexes.push_back(indexes.back() + 1);
                }
            }
        }
        return result;
    }
};
