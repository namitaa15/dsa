494. Target Sum
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer 
in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to 
build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
code-
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total= accumulate(nums.begin(),nums.end(),0);
        if((target+total)%2 !=0 || (abs(target)>total))
        {
            return 0;
        }
        int sum=(total+target)/2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int num:nums)
        {
            for(int i=sum;i>=num;i--)
            {
                dp[i] += dp[i-num];
            }
        }
        return dp[sum];
    }
};
