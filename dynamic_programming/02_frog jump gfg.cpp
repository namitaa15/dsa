class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int>dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int step1= dp[i-1] +abs(height[i]-height[i-1]);
            int step2= (i>1) ? dp[i-2] +abs(height[i]-height[i-2]):INT_MAX;
            dp[i]= min(step1,step2);
        }
        return dp[n-1];
        
    }
};
