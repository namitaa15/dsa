/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map to store original node → cloned node
        unordered_map<Node*, Node*> mp;
        // Create clone for the start node
        mp[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Go through all neighbors
            for (auto nbr : curr->neighbors) {
                if (!mp[nbr]) {
                    // Clone the neighbor if not cloned yet
                    mp[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                // Add the neighbor to the current node's clone's neighbors
                mp[curr]->neighbors.push_back(mp[nbr]);
            }
        }

        // Return the clone of the original start node
        return mp[node];
    }
};
