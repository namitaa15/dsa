int frogJump(int n, vector<int>& heights, int k) {
    vector<int> dp(n, 1e9); 
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    return dp[n - 1];
}
