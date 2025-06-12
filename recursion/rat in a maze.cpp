class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& maze, int n, string path,
               vector<string>& ans, vector<vector<int>>& vis) {
        // If reached the destination, add path to answer
        if (i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        // D, L, R, U
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0};
        string dir = "DLRU";
        
        for (int idx = 0; idx < 4; idx++) {
            int ni = i + di[idx];
            int nj = j + dj[idx];
            // Check bounds and if the cell is open and not visited
            if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                maze[ni][nj] == 1 && vis[ni][nj] == 0) {
                vis[i][j] = 1;
                solve(ni, nj, maze, n, path + dir[idx], ans, vis);
                vis[i][j] = 0; // Backtrack
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (maze[0][0] == 1) // Only if the start is open
            solve(0, 0, maze, n, "", ans, vis);
        return ans;
    }
};
