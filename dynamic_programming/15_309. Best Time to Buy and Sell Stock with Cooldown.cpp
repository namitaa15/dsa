309. Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // dp[i][0] = max profit from day i, can buy
        // dp[i][1] = max profit from day i, holding

        for(int i = n-1; i >= 0; i--) {
            // If can buy
            dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
            // If holding, can sell or hold
            dp[i][1] = max(prices[i] + dp[i+2][0], dp[i+1][1]);
            // After selling, next day must cooldown (i+2)
        }
        return dp[0][0];
    }
};
