1498. Number of Subsequences That Satisfy the Given Sum Condition
code-
  class Solution {
public:
    void func(int i, int n, vector<int>& nums, int target,
              vector<vector<int>>& result, vector<int>& current, int sum) {
        if (i == n) {
            if (sum == target) {
                result.push_back(current);
            }
            return;
        }
        current.push_back(nums[i]);
        sum += nums[i];
        func(i + 1, n, nums, target, result, current, sum);
        current.pop_back();
        sum -= nums[i];
        func(i + 1, n, nums, target, result, current, sum);
    }
    int numSubseq(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int n = nums.size();
        func(0, n, nums, target, result, current, 0);
        return result.size();
    }
};
