class Solution {
public:
    void inorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};

using stacks
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};
