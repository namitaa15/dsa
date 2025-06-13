class Solution {
  public:
    // Helper function for DFS
    bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;   // Mark node as part of current recursion stack

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, adj, visited, recStack))
                    return true;
            } else if(recStack[neighbor]) {
                // Found a back edge (cycle in directed graph)
                return true;
            }
        }

        recStack[node] = false;  // Remove from recursion stack before going back
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // Only one side, since directed
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};
