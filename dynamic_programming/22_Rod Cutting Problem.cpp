class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n + 1, 0); // dp[i] = max paisa for rod of length i

        for (int len = 1; len <= n; len++) { // Rod ki current length
            for (int cut = 1; cut <= len; cut++) { // Try every cut (1-based)
                dp[len] = max(dp[len], price[cut - 1] + dp[len - cut]);
                // price[cut-1] because price vector is 0-based
            }
        }
        return dp[n]; // poori rod ka max paisa
    }
};
