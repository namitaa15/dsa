class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> dp(n, 0); // dp[i] = min cuts for s[0..i]

        // Fill the isPalin table
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && (end - start <= 2 || isPalin[start + 1][end - 1])) {
                    isPalin[start][end] = true;
                }
            }
        }

        // Fill dp[]
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                dp[i] = 0; // whole string is palindrome
            } else {
                dp[i] = i; // worst case: cut at every char
                for (int j = 1; j <= i; j++) {
                    if (isPalin[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
