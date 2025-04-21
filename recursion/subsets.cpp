78. Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

code-
  class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(nums[index]);
        generateSubsets(nums, index + 1, currentSubset, result);
        currentSubset.pop_back();
        generateSubsets(nums, index + 1, currentSubset, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(nums, 0, currentSubset, result);
        return result;
    }
};
