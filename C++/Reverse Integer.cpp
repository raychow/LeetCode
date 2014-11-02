class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
};
