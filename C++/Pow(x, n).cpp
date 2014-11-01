class Solution
{
public:
    double pow(double x, int n)
    {
        double result = 1;
        if (n < 0)
        {
            if (!(n - 1 < n))
            {
                ++n;
                result /= x;
            }
            n = -n;
            x = 1 / x;
        }
        while (n)
        {
            if (n & 1)
            {
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
};
