class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end());
        m_result.clear();
        __subsetsWithDup(S, 0);
        return m_result;
    }

private:
    vector<int> m_subset;
    vector<vector<int>> m_result;

    void __subsetsWithDup(vector<int> &S, int i, bool isIgnore = false)
    {
        if (S.size() == i)
        {
            m_result.push_back(m_subset);
            return;
        }
        if (!isIgnore || 0 == i || S[i] != S[i - 1])
        {
            m_subset.push_back(S[i]);
            __subsetsWithDup(S, i + 1);
            m_subset.pop_back();
            __subsetsWithDup(S, i + 1, true);
        }
        else
        {
            __subsetsWithDup(S, i + 1, true);
        }
    }
};
