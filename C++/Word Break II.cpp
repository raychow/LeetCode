class Solution
{
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        vector<string> results;
        vector<deque<int>> possibleWords(s.size());
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i + 1; j <= s.size(); ++j)
            {
                if (j < s.size() && possibleWords[j].empty())
                {
                    continue;
                }
                if (dict.count(s.substr(i, j - i)))
                {
                    possibleWords[i].push_front(j);
                }
            }
        }
        __getResult(s, possibleWords, 0, results, "");
        return results;
    }

private:
    void __getResult(const string &s, vector<deque<int>> &possibleWords,
        int i, vector<string> &results, string result)
    {
        if (s.length() == i)
        {
            results.push_back(result);
            return;
        }
        for (int j : possibleWords[i])
        {
            __getResult(s, possibleWords, j, results,
                result + (0 == i ? "" : " ") + s.substr(i, j - i));
        }
    }
};
