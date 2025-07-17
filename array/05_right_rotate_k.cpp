189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
code-
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums=temp;
    }
};
📌 Input:
nums = [1, 2, 3, 4, 5]

k = 2

🔁 Step-by-Step Dry Run:
Create a temp array of size 5 → [0, 0, 0, 0, 0].

Loop through each index i in nums:

i = 0: temp[(0+2)%5] = nums[0] = 1 → temp[2] = 1

i = 1: temp[(1+2)%5] = nums[1] = 2 → temp[3] = 2

i = 2: temp[(2+2)%5] = nums[2] = 3 → temp[4] = 3

i = 3: temp[(3+2)%5] = nums[3] = 4 → temp[0] = 4

i = 4: temp[(4+2)%5] = nums[4] = 5 → temp[1] = 5

temp after loop = [4, 5, 1, 2, 3].

Copy temp back to nums.

✅ Final Output:
nums = [4, 5, 1, 2, 3]

