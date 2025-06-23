class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
             int n = a.size();
        int m = b.size();
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge two sorted arrays
        while(i < n && j < m) {
            if(a[i] < b[j])
                merged.push_back(a[i++]);
            else
                merged.push_back(b[j++]);
        }
        // Add remaining elements
        while(i < n)
            merged.push_back(a[i++]);
        while(j < m)
            merged.push_back(b[j++]);
        
        int total = merged.size();
        // Since both arrays are same size, total is even (2n)
        int mid = total / 2;
        double median = (merged[mid-1] + merged[mid]) / 2.0;
        return median;
    }
};
