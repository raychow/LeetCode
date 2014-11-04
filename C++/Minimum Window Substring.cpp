class Solution
{
public:
    string minWindow(string S, string T)
    {
        int tAlphaCount[128] = {};
        bool tSet[128] = {};
        int remain = T.size();
        int low = 0;
        int minIndex = -1;
        int minLength = numeric_limits<int>::max();
        for (char c : T)
        {
            ++tAlphaCount[c];
            tSet[c] = true;
        }
        for (int i = 0; i < S.size(); ++i)
        {
            char c = S[i];
            if (!tSet[c])
            {
                continue;
            }
            if (--tAlphaCount[c] >= 0)
            {
                --remain;
            }
            if (!remain)
            {
                while (!tSet[S[low]] || tAlphaCount[S[low]] < 0)
                {
                    if (tSet[S[low]])
                    {
                        ++tAlphaCount[S[low]];
                    }
                    ++low;
                }
                if (minLength > i - low + 1)
                {
                    minIndex = low;
                    minLength = i - low + 1;
                }
            }
        }
        return -1 == minIndex ? "" : S.substr(minIndex, minLength);
    }
};
