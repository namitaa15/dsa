130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

code-
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
    int n = board.size(), m = board[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;

    board[i][j] = '#'; // mark as safe

    dfs(board, i+1, j);
    dfs(board, i-1, j);
    dfs(board, i, j+1);
    dfs(board, i, j-1);
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();

    // Step 1: Mark border-connected 'O' as '#'
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0);
        if (board[i][m-1] == 'O') dfs(board, i, m-1);
    }
    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') dfs(board, 0, j);
        if (board[n-1][j] == 'O') dfs(board, n-1, j);
    }

    // Step 2: Flip all 'O' → 'X', and '#' → 'O'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

};
