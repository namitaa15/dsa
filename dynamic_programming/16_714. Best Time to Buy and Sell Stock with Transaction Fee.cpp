714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // dp[i][0]: profit if can buy on day i
        // dp[i][1]: profit if holding on day i

        for(int i = n-1; i >= 0; i--) {
            // Can buy
            dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
            // Holding: sell with fee, or skip
            dp[i][1] = max(prices[i] - fee + dp[i+1][0], dp[i+1][1]);
        }
        return dp[0][0];
    }
};
