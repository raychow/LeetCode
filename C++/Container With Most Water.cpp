class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high)
        {
            result = max(result, (high - low) * min(height[low], height[high]));
            if (height[low] <= height[high])
            {
                ++low;
            }
            else
            {
                --high;
            }
        }
        return result;
    }
};
