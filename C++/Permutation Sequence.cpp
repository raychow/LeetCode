int factorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    int result = n;
    while (--n)
    {
        result *= n;
    }
    return result;
}

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        stringstream ss;
        set<int> sb;
        for (int i = 1; i <= n; ++i)
        {
            sb.insert(i);
        }
        --k;
        int fac = factorial(n - 1);
        for (int i = 0; i < n; ++i)
        {
            int index = k / fac;
            k %= fac;
            fac /= max(n - i - 1, 1);
            auto iter = sb.begin();
            while (index--)
            {
                ++iter;
            }
            ss << *iter;
            sb.erase(iter);
        }
        return ss.str();
    }
};
