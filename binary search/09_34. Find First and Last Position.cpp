34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
  class Solution {
public:
    int lower(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;

    }
    int upper(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower(nums,target);
        int ub=upper(nums,target);
        int n=nums.size();
        if(lb==n || nums[lb]!=target)
        {
            return {-1,-1};
        }
        return {lb,ub-1};
    }

};
