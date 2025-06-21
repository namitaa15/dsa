class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points) {
        // Code here
        int n=points.size();
         vector<vector<int>> dp(n, vector<int>(4, 0));
    // dp[day][last] = max points till 'day' if last activity was 'last'

    // Base case for day 0
    for (int last = 0; last < 4; last++) {
        int maxi = 0;
        for (int act = 0; act < 3; act++) {
            if (act != last) {
                maxi = max(maxi, points[0][act]);
            }
        }
        dp[0][last] = maxi;
    }

    // Fill for day 1 to n-1
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int act = 0; act < 3; act++) {
                if (act != last) {
                    int point = points[day][act] + dp[day - 1][act];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    // Answer: last day, last activity can be anything (0,1,2,3)
    return dp[n - 1][3];
    }
};
