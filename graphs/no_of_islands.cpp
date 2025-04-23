200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

code-
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
    int n = grid.size(), m = grid[0].size();
    // Check boundaries or if it's already water
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') return;

    grid[i][j] = '0'; // Mark as visited

    // Check all 4 directions
    dfs(grid, i+1, j); // Down
    dfs(grid, i-1, j); // Up
    dfs(grid, i, j+1); // Right
    dfs(grid, i, j-1); // Left
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                count++;        // Found new island
                dfs(grid, i, j); // Mark all connected land
            }
        }
    }
    return count;
}
};
