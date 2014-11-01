class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return '1' <= s.front() && s.front() <= '9';
        }
        int front1 = 1;
        int front2 = 0;
        int result = !('0' == s.front());
        for (int i = 1; i < s.size(); ++i)
        {
            front2 = front1;
            front1 = result;
            result = ('0' == s[i] ? 0 : front1)
                + ('1' == s[i - 1] || ('2' == s[i - 1] && '7' > s[i])
                ? front2 : 0);
            if (!result)
            {
                break;
            }
        }
        return result;
    }
};
