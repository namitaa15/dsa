1129. Shortest Path with Alternating Colors
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1.
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]

code-
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n);
        for (auto& e : redEdges)
            redGraph[e[0]].push_back(e[1]);
        for (auto& e : blueEdges)
            blueGraph[e[0]].push_back(e[1]);

        vector<vector<bool>> visited(
            n, vector<bool>(2, false)); // [0]=red, [1]=blue
        vector<int> res(n, -1);

        queue<tuple<int, int, int>> q; // node, color(0=red,1=blue), dist

        q.push({0, 0, 0}); // Start with red
        q.push({0, 1, 0}); // Start with blue
        visited[0][0] = visited[0][1] = true;
        res[0] = 0;

        while (!q.empty()) {
            auto [node, color, dist] = q.front();
            q.pop();

            // Alternate color
            if (color == 0) { // last was red, now go to blue neighbors
                for (int nei : blueGraph[node]) {
                    if (!visited[nei][1]) {
                        visited[nei][1] = true;
                        q.push({nei, 1, dist + 1});
                        if (res[nei] == -1)
                            res[nei] = dist + 1;
                    }
                }
            } else { // last was blue, now go to red neighbors
                for (int nei : redGraph[node]) {
                    if (!visited[nei][0]) {
                        visited[nei][0] = true;
                        q.push({nei, 0, dist + 1});
                        if (res[nei] == -1)
                            res[nei] = dist + 1;
                    }
                }
            }
        }

        return res;
    }
};
