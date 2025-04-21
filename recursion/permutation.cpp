46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
  class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            // Choose
            used[i] = true;
            temp.push_back(nums[i]);

            // Explore
            backtrack(nums, temp, used, res);

            // Un-choose (backtrack)
            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used, res);
        return res;
    }
};
