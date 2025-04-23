207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

code-
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    // Step 1: Build graph
    for (auto& pre : prerequisites) {
        int course = pre[0], prereq = pre[1];
        adj[prereq].push_back(course);
        indegree[course]++;
    }

    // Step 2: Queue all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0; // how many courses we can take

    // Step 3: BFS
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count == numCourses; // true = no cycle
}
};
