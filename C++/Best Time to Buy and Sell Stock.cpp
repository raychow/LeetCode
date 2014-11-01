class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int lowest = prices[0];
        int result = 0;
        for (int i = 0; i != prices.size(); ++i)
        {
            result = max(prices[i] - lowest, result);
            lowest = min(prices[i], lowest);
        }
        return result;
    }
};
