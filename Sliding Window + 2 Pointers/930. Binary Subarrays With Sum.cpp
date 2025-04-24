930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
class Solution {
public:
    int func(vector<int>& nums, int goal)
    {
        if(goal<0)
        {
            return 0;
        }
        int r=0;
        int l=0;
        int cnt=0;
        int sum=0;
        int n=nums.size();
        while(r<n)
        {
            sum=sum+nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (func(nums,goal)-func(nums,goal-1));
    }
};
