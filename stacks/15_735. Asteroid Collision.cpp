class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                while(!ans.empty() && ans.back()>0 && ans.back()<abs(nums[i]))
                {
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back()==abs(nums[i]))
                {
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back()<0)
                {
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
