bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // If it's a leaf node
    if (!root->left && !root->right)
        return targetSum == root->val;

    int remaining = targetSum - root->val;

    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}
