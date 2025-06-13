class Solution {
  public:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!visited[v]) {
                topoSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list with weights
        vector<pair<int,int>> adj[V];
        for(auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
        }
        
        // Step 2: Topological sort
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i])
                topoSort(i, adj, visited, st);
        }
        
        // Step 3: Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0; // assuming source is 0
        
        // Step 4: Relax edges in topological order
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Step 5: Replace 1e9 with -1 for unreachable nodes
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
