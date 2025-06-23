class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n-2; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if(sum == target)
                    return true;
                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }
        return false;
    }
};
