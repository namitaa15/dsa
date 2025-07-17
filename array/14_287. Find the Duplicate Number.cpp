class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto const &i: mp)
        {
            if(i.second>=2)
            {
                int k=i.first;
                return k;
            }
        }
        return 0;
    }
};
