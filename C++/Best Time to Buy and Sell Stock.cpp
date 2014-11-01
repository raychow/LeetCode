class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        vector<int> profits(prices.size() - 1);
        for (int i = 0; i != prices.size() - 1; ++i)
        {
            profits[i] = prices[i + 1] - prices[i];
        }
        int result = 0;
        int currentProfit = 0;
        for (int profit : profits)
        {
            currentProfit += profit;
            result = max(result, currentProfit);
            currentProfit = max(0, currentProfit);
        }
        return result;
    }
};
