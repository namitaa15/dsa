class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preIdx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIdx];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find rootVal index in inorder
        int inIdx = inStart;
        while (inorder[inIdx] != rootVal) inIdx++;
        
        int leftCount = inIdx - inStart;
        root->left  = build(preorder, inorder, preIdx + 1, inStart, inIdx - 1);
        root->right = build(preorder, inorder, preIdx + 1 + leftCount, inIdx + 1, inEnd);
        
        return root;
    }
};
