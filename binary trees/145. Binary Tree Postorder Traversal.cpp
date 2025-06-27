class Solution {
public:
    void postorder(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};

using stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);   // Store root

            // Pehle left, fir right push karo (so that right pehle aaye output me)
            if (node->left != NULL)
                st.push(node->left);
            if (node->right != NULL)
                st.push(node->right);
        }

        // Ab ans me hai Root, Right, Left — hume chahiye Left, Right, Root
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
