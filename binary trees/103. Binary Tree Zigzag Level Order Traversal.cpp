class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)
        {
            return result;
        }
        queue<TreeNode*>qn;
        qn.push(root);
        bool lr=true;
        while(!qn.empty())
        {
            int n=qn.size();
            vector<int>row(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node=qn.front();
                qn.pop();
                int index=lr?i:n-i-1;
                row[index]=node->val;
                if(node->left)
                {
                    qn.push(node->left);
                }
                if(node->right)
                {
                    qn.push(node->right);
                }
            }
            lr=!lr;
            result.push_back(row);
        }
        return result;
    }
};
