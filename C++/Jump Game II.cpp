class Solution
{
public:
    int jump(int A[], int n)
    {
        if (n <= 0)
        {
            return -1;
        }
        int nMaxReach = 0;
        int nNextMaxReach = 0;
        int nStep = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i > nMaxReach)
            {
                ++nStep;
                if (nNextMaxReach >= n - 1)
                {
                    return nStep;
                }
                nMaxReach = nNextMaxReach;
            }
            nNextMaxReach = max(nNextMaxReach, i + A[i]);
        }
        return nStep;
    }
};