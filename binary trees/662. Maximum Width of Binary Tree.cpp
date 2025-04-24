int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    int maxWidth = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});  // {node, index}

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second;
        unsigned long long first, last;

        for (int i = 0; i < size; i++) {
            auto [node, idx] = q.front(); q.pop();
            idx -= minIndex;  // Normalize to avoid overflow

            if (i == 0) first = idx;
            if (i == size - 1) last = idx;

            if (node->left)
                q.push({node->left, 2 * idx + 1});
            if (node->right)
                q.push({node->right, 2 * idx + 2});
        }

        maxWidth = max(maxWidth, (int)(last - first + 1));
    }

    return maxWidth;
}
