TreeNode* findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Node found: handle 3 cases

        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        else if (!root->left || !root->right) {
            TreeNode* child = root->left ? root->left : root->right;
            delete root;
            return child;
        }

        // Case 3: Two children
        else {
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }

    return root;
}
