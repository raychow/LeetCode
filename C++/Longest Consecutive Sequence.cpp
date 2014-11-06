class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        unordered_set<int> set(num.cbegin(), num.cend());
        int result = 0;
        while (!set.empty())
        {
            int count = 1;
            int i = *set.cbegin();
            set.erase(i);
            for (int j = i + 1; set.count(j); ++j)
            {
                ++count;
                set.erase(j);
            }
            for (int j = i - 1; set.count(j); --j)
            {
                ++count;
                set.erase(j);
            }
            result = max(result, count);
        }
        return result;
    }
};
