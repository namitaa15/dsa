// Leetcode Problem: 228. Summary Ranges
// Link: https://leetcode.com/problems/summary-ranges/

// Problem Statement:
// Given a sorted integer array nums without duplicates, return the summary of its ranges.

//  Example:
// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]

// Approach:
// Traverse the array, and for every range of consecutive numbers, store the range in "start->end" format.
// If only one number, store it as a single string.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;

        int start = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        // Handle the last range
        if (start == nums[n - 1]) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
        }

        return ans;
    }
};
