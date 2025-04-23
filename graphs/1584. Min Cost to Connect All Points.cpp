1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|,
  where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected 
if there is exactly one simple path between any two points.
Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

class Solution {
public:
    int manhattanDist(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    int edgesUsed = 0, cost = 0;

    // Min-heap: {weight, to_node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.push({0, 0}); // start from point 0

    while (edgesUsed < n) {
        auto [wt, curr] = minHeap.top(); minHeap.pop();
        if (inMST[curr]) continue;

        inMST[curr] = true;
        cost += wt;
        edgesUsed++;

        // push all edges from curr to others
        for (int next = 0; next < n; ++next) {
            if (!inMST[next]) {
                int dist = manhattanDist(points[curr], points[next]);
                minHeap.push({dist, next});
            }
        }
    }

    return cost;
}
};
