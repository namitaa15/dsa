class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* node = q.front(); q.pop();
                if (i == 0) ans.push_back(node->data); // first node of this level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
