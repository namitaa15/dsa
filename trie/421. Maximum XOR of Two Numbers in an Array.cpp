class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // 32 bits for int
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Prefer the opposite bit if possible
            if (node->children[1 - bit]) {
                maxXOR |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)
            insert(num);
        
        int res = 0;
        for (int num : nums)
            res = max(res, findMaxXOR(num));
        return res;
    }
};
