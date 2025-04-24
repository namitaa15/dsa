class Solution {
public:
    int candy(vector<int>&num) {
        int n=num.size();
        vector<int>c(n,1);
        for(int i=1;i<n;i++)
        {
            if(num[i]>num[i-1])
            {
                c[i]=c[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(num[i]>num[i+1])
            {
                c[i]=max(c[i],c[i+1]+1);
            }
        }
        int sum=accumulate(c.begin(),c.end(),0);
        return sum;

    }
};
