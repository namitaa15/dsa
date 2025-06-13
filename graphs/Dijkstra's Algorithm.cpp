class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list with weights
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // comment this line for directed graph
        }
        
        // Step 2: Init distance array and min-heap (priority queue)
        vector<int> dist(V, 1e9); // Large number as INF
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src}); // {distance, node}
        
        // Step 3: Main Dijkstra's loop
        while(!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &nbr : adj[node]) {
                int next = nbr.first, weight = nbr.second;
                if(dist[next] > currDist + weight) {
                    dist[next] = currDist + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        
        // Optional: Make unreachable as -1
        for(int i = 0; i < V; i++)
            if(dist[i] == 1e9) dist[i] = -1;
        return dist;
    }
};
