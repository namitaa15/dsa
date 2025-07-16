378. Kth Smallest Element in a Sorted Matrix
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

class Solution {
public:
    bool countLessEqual(vector<vector<int>>& matrix, int mid, int& count) {
    int n = matrix.size();
    int i = n - 1, j = 0;
    count = 0;

    while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) {
            count += i + 1;  // All elements in column up to i are <= mid
            j++;
        } else {
            i--;
        }
    }

    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        countLessEqual(matrix, mid, count);

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

};
