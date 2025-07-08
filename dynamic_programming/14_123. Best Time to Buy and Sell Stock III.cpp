123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[transactions_left][holding_status]
        // holding_status: 0 = can buy, 1 = holding
        vector<vector<int>> dp(3, vector<int>(2, 0));

        // Traverse backwards, so use two arrays for rolling (space optimized)
        for (int i = n-1; i >= 0; i--) {
            for (int k = 1; k <= 2; k++) { // transaction count
                // Not holding, can buy
                dp[k][0] = max(-prices[i] + dp[k][1], dp[k][0]);
                // Holding, can sell
                dp[k][1] = max(prices[i] + dp[k-1][0], dp[k][1]);
            }
        }
        // At day 0, can do 2 transactions, not holding anything
        return dp[2][0];
    }
};
