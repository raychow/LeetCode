class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        int currentCount = 0;
        int low = 0;
        vector<bool> vbCache(128);
        for (int i = 0; i != s.size(); ++i)
        {
            if (vbCache[s[i]])
            {
                while (s[low] != s[i])
                {
                    vbCache[s[low]] = false;
                    --currentCount;
                    ++low;
                }
                ++low;
                continue;
            }
            vbCache[s[i]] = true;
            ++currentCount;
            result = max(result, currentCount);
        }
        return result;
    }
};
