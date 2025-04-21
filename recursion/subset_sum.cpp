Problem Statement:
Given a list of n integers, print the sum of all possible subsets in increasing order.

Example:
Input: nums = [3, 1, 2]
Output: [0, 1, 2, 3, 3, 4, 5, 6]
Explanation: All subset sums are:  
→ [] → 0  
→ [1] → 1  
→ [2] → 2  
→ [3] → 3  
→ [1,2] → 3  
→ [1,3] → 4  
→ [2,3] → 5  
→ [1,2,3] → 6  
✅ C++ Code (Recursive Approach):
#include <bits/stdc++.h>
using namespace std;

void findSubsetSums(int index, int sum, vector<int>& arr, int n, vector<int>& result) {
    if (index == n) {
        result.push_back(sum); // 🟢 Base case: store the subset sum
        return;
    }

    // ✅ Pick the current element
    findSubsetSums(index + 1, sum + arr[index], arr, n, result);

    // ❌ Don't pick the current element
    findSubsetSums(index + 1, sum, arr, n, result);
}

vector<int> subsetSums(vector<int> &arr, int n) {
    vector<int> result;
    findSubsetSums(0, 0, arr, n, result);
    sort(result.begin(), result.end()); // 🔃 Sort in increasing order
    return result;
}
