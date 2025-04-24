class Solution {
public: 
    void dfs(TreeNode* node, int level, vector<int>& result) {
    if (!node) return;

    if (level == result.size())
        result.push_back(node->val);

    dfs(node->right, level + 1, result); // Right first
    dfs(node->left, level + 1, result);
}

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
    dfs(root, 0, result);
    return result;

    }
};
