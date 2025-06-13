class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> distance(n, -1);   // distance array, initially sab -1
        queue<int> q;

        distance[src] = 0; // src se src ka distance 0
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbor : adj[node]) {
                if(distance[neighbor] == -1) { // pehli baar visit ho raha
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return distance;
    }
};
