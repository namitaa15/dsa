class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<int> adj[V];
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // u -> v
        }

        // Step 2: Calculate indegree for each node
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int nbr : adj[i])
                indegree[nbr]++;
        }

        // Step 3: Push nodes with indegree 0 to queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        // Step 4: Process queue and build result
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for(int nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        // If topo.size() < V, there is a cycle (optional to check)
        return topo;
    }
};
