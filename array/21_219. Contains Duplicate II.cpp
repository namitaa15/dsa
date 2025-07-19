class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; // number, last_index
    for(int i = 0; i < nums.size(); i++) {
        if(m.count(nums[i])) {
            if(i - m[nums[i]] <= k)
                return true;
        }
        m[nums[i]] = i; // Update last index of nums[i]
    }
    return false;
    }
};
