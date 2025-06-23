class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if(n <= 2) return 0;  // Paani hi nahi ruke

        vector<int> leftMax(n), rightMax(n);

        // Fill left max
        leftMax[0] = arr[0];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], arr[i]);

        // Fill right max
        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], arr[i]);

        int water = 0;
        for(int i = 0; i < n; i++) {
            int w = min(leftMax[i], rightMax[i]) - arr[i];
            if(w > 0) water += w;
        }
        return water;
    }
};
