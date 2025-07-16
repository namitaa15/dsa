240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int r = 0, c = cols - 1;  // Start from top-right corner

    while (r < rows && c >= 0) {
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] > target)
            c--;  // Move left
        else
            r++;  // Move down
    }

    return false;
}
};
