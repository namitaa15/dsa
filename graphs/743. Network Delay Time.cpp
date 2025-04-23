743. Network Delay Time
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as 
directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time 
it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
code-
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto& time : times) {
        int u = time[0], v = time[1], w = time[2];
        adj[u].push_back({v, w});
    }

    // Min-heap: {time, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [time, node] = pq.top(); pq.pop();

        for (auto& [neighbor, wt] : adj[node]) {
            if (dist[neighbor] > time + wt) {
                dist[neighbor] = time + wt;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e9) return -1; // unreachable node
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}
};
