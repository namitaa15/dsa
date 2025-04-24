1248. Count Number of Nice Subarrays
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=1;
            }
        }
        return (func(nums,k)-func(nums,k-1));
    }
};
