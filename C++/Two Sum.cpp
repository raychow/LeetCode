class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> umNumber;
        for (int i = 0; i != numbers.size(); ++i)
        {
            auto iter = umNumber.find(target - numbers[i]);
            if (iter != umNumber.end())
            {
                return vector<int> {iter->second + 1, i + 1};
            }
            umNumber[numbers[i]] = i;
        }
        return vector<int>();
    }
};
