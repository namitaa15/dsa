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
        map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());

        // Sort by frequency (descending)
        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};
