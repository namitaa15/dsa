416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that 
the sum of the elements in both subsets is equal or false otherwise.
Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
code-
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
        {
            return false;
        }
        int target=sum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        if(nums[0]<=target)
        {
            dp[nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int t=target;t>=nums[i];t--)
            {
                dp[t]=dp[t]||dp[t-nums[i]];
            }
        }
        return dp[target];
    }
};
