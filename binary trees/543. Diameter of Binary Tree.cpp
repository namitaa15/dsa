class Solution {
public:
    int height(TreeNode* root,int &d)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=height(root->left,d);
        int r=height(root->right,d);
        d=max(d,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root,d);
        return d;
    }
};
