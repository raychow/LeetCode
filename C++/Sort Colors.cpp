class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int begin = 0;
        int current = 0;
        int end = n - 1;
        while (current <= end)
        {
            switch (A[current])
            {
            case 0:
                swap(A[begin], A[current]);
                ++begin;
                ++current;
                break;
            case 1:
                ++current;
                break;
            case 2:
                swap(A[current], A[end]);
                --end;
                break;
            }
        }
    }
};
