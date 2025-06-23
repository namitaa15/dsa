class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;          // Already at last
        if(arr[0] == 0) return -1;    // Can't move at all

        int jumps = 1;                // First jump
        int farthest = arr[0];       
        int currEnd = arr[0];         
        for(int i = 1; i < n-1; i++) {
            farthest = max(farthest, i + arr[i]);  

            if(i == currEnd) {                      
                jumps++;                           
                currEnd = farthest;                 

                if(currEnd >= n-1) break;          
            }
        }

        return currEnd >= n-1 ? jumps : -1;         
    }
};
