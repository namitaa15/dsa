class Solution {
  public:
    bool bfs(int start, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int,int>> q; // {currentNode, parent}
        q.push({start, -1});
        visited[start] = true;

        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto nbr : adj[node]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});
                } else if(nbr != par) {
                    // Found a back edge, cycle exists
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<int> adj[V];
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(bfs(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
