class Solution {
public:
    vector<vector<string>> result;

    void solve(int row, int n, vector<string>& board,
               vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue; // queen attacking position
            }

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            solve(row + 1, n, board, cols, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);             // column attack check
        vector<bool> diag1(2 * n - 1, false);    // main diagonal (row + col)
        vector<bool> diag2(2 * n - 1, false);    // anti-diagonal (row - col + n - 1)

        solve(0, n, board, cols, diag1, diag2);
        return result;
    }
};
