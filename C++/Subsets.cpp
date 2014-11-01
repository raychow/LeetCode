class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        m_result.clear();
        __subsets(S, 0);
        return m_result;
    }

private:
    vector<int> m_subset;
    vector<vector<int>> m_result;

    void __subsets(vector<int> &S, int i)
    {
        if (S.size() == i)
        {
            m_result.push_back(m_subset);
            return;
        }
        m_subset.push_back(S[i]);
        __subsets(S, i + 1);
        m_subset.pop_back();
        __subsets(S, i + 1);
    }
};
