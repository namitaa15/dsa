994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

code-
  class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<pair<int, int>, int>> q; // {{i, j}, time}
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Step 1: Push all initially rotten oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }

    int time = 0;
    int drow[] = {-1, 0, 1, 0}; // up, right, down, left
    int dcol[] = {0, 1, 0, -1};

    // Step 2: BFS
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time, t);

        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                grid[nr][nc] == 1 && visited[nr][nc] == 0) {
                q.push({{nr, nc}, t + 1});
                visited[nr][nc] = 2; // mark as rotten
            }
        }
    }

    // Step 3: Check for any fresh orange left
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1 && visited[i][j] != 2)
                return -1;

    return time;
}
};
