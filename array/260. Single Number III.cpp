Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

  class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto const &it:mp)
        {
            if(it.second==1)
            {
                int ans=it.first;
                result.push_back(ans);
            }
        }
        return result;
    }
};
