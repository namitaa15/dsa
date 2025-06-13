class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for(int nbr : adj[node]) {
            if(!visited[nbr])
                dfs(nbr, adj, visited, st);
        }
        st.push(node); // DFS ke baad stack mein daalo
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!visited[i])
                dfs(i, adj, visited, st);
        }

        vector<int> topo;
        while(!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
