/* Leetcode 213  House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
class Solution {
public:
    int robber(vector<int>& nums,int s,int e)
    {
        int len = e - s + 1;
        if (len == 1) return nums[s];

        vector<int> dp(len);
        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s + 1]);

        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 1], nums[s + i] + dp[i - 2]);
        }
        return dp[len - 1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        int n1=robber(nums,0,n-2);
        int n2=robber(nums,1,n-1);
        return max(n1,n2);
    }
};
