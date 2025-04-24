class Solution {
public:
    int trap(vector<int>& h) {
        int lmax=0;
        int rmax=0;
        int total=0;
        int n=h.size();
        int l=0;
        int r=n-1;
        while (l <= r) {
        if (h[l] <= h[r]) {
            if (h[l] >= lmax) {
                lmax = h[l];
            } else {
                total += lmax - h[l];
            }
            l++;
        } else {
            if (h[r] >= rmax) {
                rmax = h[r];
            } else {
                total += rmax - h[r];
            }
            r--;
        }
    }
    
    return total;

    }
};
