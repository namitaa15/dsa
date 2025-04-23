1901. Find a Peak Element II
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int left = 0, right = cols - 1;

    while (left <= right) {
        int midCol = (left + right) / 2;
        
        // Find max in mid column
        int maxRow = 0;
        for (int i = 0; i < rows; i++) {
            if (mat[i][midCol] > mat[maxRow][midCol])
                maxRow = i;
        }

        // Compare with left and right neighbors
        bool leftIsBigger = midCol - 1 >= 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol];
        bool rightIsBigger = midCol + 1 < cols && mat[maxRow][midCol + 1] > mat[maxRow][midCol];

        if (!leftIsBigger && !rightIsBigger) {
            return {maxRow, midCol};  // Found a peak
        } else if (rightIsBigger) {
            left = midCol + 1;
        } else {
            right = midCol - 1;
        }
    }

    return {-1, -1}; // Just for safety, should not happen
}
};
