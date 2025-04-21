31. Next Permutation
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
code-
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());

    }
};
 Input:

nums = [1, 3, 5, 4, 2]
Step-by-step Dry Run:
Step 1: Find the break point (first index i from right where nums[i] < nums[i+1])

Start from i = 3 → nums[3] = 4, nums[4] = 2 → 4 > 2 ❌
i = 2 → nums[2] = 5, nums[3] = 4 → 5 > 4 ❌
i = 1 → nums[1] = 3, nums[2] = 5 → ✅ Found break point at i = 1
Now nums[i] = 3 — this is the element we’ll try to swap with a just greater number on the right.

Step 2: Find the first number nums[j] from the right such that nums[j] > nums[i]

Start from j = 4 → nums[4] = 2 → 2 < 3 ❌
j = 3 → nums[3] = 4 → 4 > 3 ✅ found j = 3
👉 Swap nums[1] = 3 and nums[3] = 4

🔁 After swap:

nums = [1, 4, 5, 3, 2]
Step 3: Reverse everything after index i = 1 → reverse from index 2 to end

Before reverse: [1, 4, 5, 3, 2]
Reverse part:   [5, 3, 2] → becomes [2, 3, 5]

Final array:    [1, 4, 2, 3, 5]
