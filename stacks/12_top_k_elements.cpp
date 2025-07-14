/*
Leetcode 347 - Top K Frequent Elements
🔗 https://leetcode.com/problems/top-k-frequent-elements/

Problem:
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.
You may return the answer in any order.

 Input: nums = [1,1,1,2,2,3], k = 2  
 Output: [1,2]

Approach:
1. Count the frequency of each number using a map.
2. Store map elements in a vector of pairs.
3. Sort the vector by frequency in descending order.
4. Pick the top `k` elements and return them.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for(int n : nums) {
        freq[n]++;
    }

    // Step 2: Bucket banao (index = frequency)
    vector<vector<int>> bucket(n + 1);
    for(auto& p : freq) {
        bucket[p.second].push_back(p.first); // freq par kaunse numbers aaye
    }

    // Step 3: Answer collect karo, frequency zyada se kam
    vector<int> ans;
    for(int i = n; i >= 1 && ans.size() < k; i--) {
        for(int num : bucket[i]) {
            ans.push_back(num);
            if(ans.size() == k) break;
        }
    }
    return ans;
}

};
