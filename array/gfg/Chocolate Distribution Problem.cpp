class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int n=a.size();
        int l=0;
        int r=m-1;
        int mini=INT_MAX;
        while(l<n && r<n && r-l+1==m)
        {
            mini=min(mini,a[r]-a[l]);
            r++;
            l++;
        }
        return mini;
    }
};
