class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        // Inorder me root ka index find karo
        int inIdx = inStart;
        while (inorder[inIdx] != rootVal) inIdx++;
        
        int leftCount = inIdx - inStart;
        
        // Left subtree
        root->left = build(inorder, inStart, inIdx - 1,
                           postorder, postStart, postStart + leftCount - 1);
        // Right subtree
        root->right = build(inorder, inIdx + 1, inEnd,
                            postorder, postStart + leftCount, postEnd - 1);
        
        return root;
    }
};
