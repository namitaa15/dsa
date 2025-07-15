class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        
        vector<bool>visited(n,false);
        queue<int>q;
        vector<int>result;
        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(int neighbor: adj[node])
            {
                if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
            
        }
        return result;
    }
};
