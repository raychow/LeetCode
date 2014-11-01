class Solution
{
public:
    bool canJump(int A[], int n)
    {
        if (n <= 1)
        {
            return true;
        }
        int nRange = A[0];
        for (int i = 1; i < n - 1 && i <= nRange && nRange < n - 1; ++i)
        {
            nRange = max(nRange, i + A[i]);
        }
        return nRange >= n - 1;
    }
};
