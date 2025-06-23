class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        for(int i = 0; i < k; i++) {
            int min_idx = i;
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Use built-in swap function
            swap(arr[i], arr[min_idx]);
        }
        return arr[k-1];
    }
};

sol 2
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end()); 
        return arr[k-1]; 
        
    }
};
