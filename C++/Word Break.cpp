class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        if (s.empty())
        {
            return false;
        }
        vector<bool> vbCanBreak(s.size());
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (!vbCanBreak[j]
                    && (s.size() - 1 == i || vbCanBreak[i + 1])
                    && dict.find(s.substr(j, i - j + 1)) != dict.end())
                {
                    vbCanBreak[j] = true;
                }
            }
        }
        return vbCanBreak[0];
    }
};
