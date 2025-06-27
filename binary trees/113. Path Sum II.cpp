class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return;

        path.push_back(root->val);

        // Leaf node check
        if (!root->left && !root->right) {
            if (targetSum == root->val)
                ans.push_back(path); // add current path to answer
        } else {
            solve(root->left, targetSum - root->val, path, ans);
            solve(root->right, targetSum - root->val, path, ans);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, path, ans);
        return ans;
    }
};
