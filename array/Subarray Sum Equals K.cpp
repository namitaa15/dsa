Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            int r = sum - k;
            if (mp.find(r) != mp.end()) {
                cnt += mp[r];
            }
            mp[sum]++;
        }
        return cnt;
    }    
};
