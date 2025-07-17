class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
                return ans;
            }
        }
        return -1;
    }
};
