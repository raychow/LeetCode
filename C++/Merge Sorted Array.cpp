class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        if (!A || !B)
        {
            return;
        }
        int i = m + n - 1;
        while (m && n)
        {
            A[i--] = A[m - 1] > B[n - 1] ? A[--m] : B[--n];
        }
        while (n)
        {
            A[i--] = B[--n];
        }
    }
};
