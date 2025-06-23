class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        unordered_set<int> s; // Store prefix sums
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == 0 || s.find(sum) != s.end()) {
               
                return true;
            }
            s.insert(sum); 
        }
        return false; 
    }
};
