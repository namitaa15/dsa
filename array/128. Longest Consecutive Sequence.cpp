class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=1;
        int maxi=1;
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==(nums[i]-1))
            {
                l++;
            }
            else if(nums[i]!=nums[i-1])
            {
                l=1;
            }
            maxi=max(l,maxi);
        }
        return maxi;
    }
};
