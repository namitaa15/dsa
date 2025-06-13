class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;  // total weight of MST

        pq.push({0, 0}); // {weight, node}

        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) continue;

            visited[node] = true;
            sum += wt;

            for(auto &nbr : adj[node]) {
                int v = nbr[0], w = nbr[1];
                if(!visited[v]) {
                    pq.push({w, v});
                }
            }
        }

        return sum;
    }
};
