Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(const auto &i: mp)
        {
            if(i.second>(n/3))
            {
                int c=i.first;
                ans.push_back(c);
            }
        }
        return ans;
    }
};
