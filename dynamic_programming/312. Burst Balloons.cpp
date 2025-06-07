class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add 1 at the beginning and end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // New size becomes n + 2
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Build up from shorter intervals to longer ones
        for (int len = 2; len <= n + 1; len++) {
            for (int i = 0; i <= n + 1 - len; i++) {
                int j = i + len;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + nums[i]*nums[k]*nums[j] + dp[k][j]);
                }
            }
        }

        return dp[0][n + 1]; // Whole range
    }
};
