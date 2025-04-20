class Solution {
public:
    bool check(vector<int>& nums) {
         int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[n-1]>nums[0])
        {
            count++;
        }
        return count<=1;
        
    }
};
📌 Example 1: [3, 4, 5, 1, 2]
This is sorted and rotated.

Step-by-step:
i = 1 → 3 < 4 → ok
i = 2 → 4 < 5 → ok
i = 3 → 5 > 1 → count = 1 ❗
i = 4 → 1 < 2 → ok

Now check nums[4] > nums[0]: 2 > 3? ❌ no → don't increase count
Final count = 1 → return true ✅

📌 Example 2: [2, 1, 3, 4]
This is NOT sorted and rotated.

Step-by-step:
i = 1 → 2 > 1 → count = 1 ❗
i = 2 → 1 < 3 → ok
i = 3 → 3 < 4 → ok

Now check nums[3] > nums[0]: 4 > 2 → ✅ count = 2 ❗❗

Final count = 2 → return false ❌
