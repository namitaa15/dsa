class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        double maxi=INT_MIN;
        double p=1;
       double s=1;
        for(int i=0;i<n;i++)
        {
            if(p==0)
            {
                p=1;
            }
            if(s==0)
            {
                s=1;
            }
            p=p*nums[i];
            s=s*nums[n-i-1];
            maxi=max(maxi,max(p,s));
        }    
        return maxi;
    }
};
