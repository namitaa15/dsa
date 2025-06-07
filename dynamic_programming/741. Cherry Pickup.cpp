class Solution {
public:
    int dp[50][50][50];

int solve(vector<vector<int>>& grid, int x1, int y1, int x2) {
    int y2 = x1 + y1 - x2; // Since steps are equal: x1 + y1 == x2 + y2

    int n = grid.size();
    
    if (x1 >= n || y1 >= n || x2 >= n || y2 >= n ||
        grid[x1][y1] == -1 || grid[x2][y2] == -1)
        return INT_MIN;

    if (x1 == n-1 && y1 == n-1)
        return grid[x1][y1];

    if (dp[x1][y1][x2] != -1)
        return dp[x1][y1][x2];

    int cherries = 0;
    if (x1 == x2 && y1 == y2)
        cherries += grid[x1][y1];  // both at same cell
    else
        cherries += grid[x1][y1] + grid[x2][y2];

    int next = max({
        solve(grid, x1+1, y1, x2+1),
        solve(grid, x1+1, y1, x2),
        solve(grid, x1, y1+1, x2+1),
        solve(grid, x1, y1+1, x2)
    });

    cherries += next;

    return dp[x1][y1][x2] = cherries;
}

int cherryPickup(vector<vector<int>>& grid) {
    memset(dp, -1, sizeof(dp));
    int result = solve(grid, 0, 0, 0);
    return max(0, result);
}

};
