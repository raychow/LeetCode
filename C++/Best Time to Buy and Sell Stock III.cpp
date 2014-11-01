class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        vector<int> leftResult(prices.size());
        vector<int> rightResult(prices.size());
        int lowest = prices.front();
        int highest = prices.back();
        int result = 0;
        for (int i = 1; i != prices.size(); ++i)
        {
            leftResult[i] = max(prices[i] - lowest, leftResult[i - 1]);
            lowest = min(prices[i], lowest);
        }
        for (int i = prices.size() - 2; i >= 0; --i)
        {
            rightResult[i] = max(rightResult[i + 1], highest - prices[i]);
            highest = max(prices[i], highest);
            result = max(leftResult[i] + rightResult[i], result);
        }
        return result;
    }
};
