class Solution
{
public:
    int climbStairs(int n)
    {
        if (1 == n)
        {
            return 1;
        }
        if (2 == n)
        {
            return 2;
        }
        n -= 2;
        int pre2 = 1;
        int pre1 = 1;
        int result = 2;
        while (n--)
        {
            pre2 = pre1;
            pre1 = result;
            result = pre1 + pre2;
        }
        return result;
    }
};
