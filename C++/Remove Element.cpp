class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        if (!A)
        {
            return 0;
        }
        int newLocation = 0;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != elem)
            {
                A[newLocation++] = A[i];
            }
        }
        return newLocation;
    }
};
