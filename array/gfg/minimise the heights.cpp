#include <algorithm>
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0]; // initial difference
        
        for(int i = 1; i < n; i++) {
            if(arr[i] - k < 0) continue; // negative height allowed nahi
            int min_height = min(arr[0] + k, arr[i] - k);
            int max_height = max(arr[i-1] + k, arr[n-1] - k);
            ans = min(ans, max_height - min_height);
        }
        return ans;
    }
};
