class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;

        // Step 1: Add all positive elements (order same)
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0)
                temp.push_back(arr[i]);
        }

        // Step 2: Add all negative elements (order same)
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0)
                temp.push_back(arr[i]);
        }

        // Step 3: Copy temp to arr
        for(int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};
