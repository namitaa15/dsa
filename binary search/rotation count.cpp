class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        int minIndex = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // Left part sorted
            if(arr[low] <= arr[mid]) {
                if(arr[low] < mini) {
                    mini = arr[low];
                    minIndex = low;
                }
                low = mid + 1;
            } else {
                if(arr[mid] < mini) {
                    mini = arr[mid];
                    minIndex = mid;
                }
                high = mid - 1;
            }
        }
        return minIndex;
    }
};
