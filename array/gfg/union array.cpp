class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        vector<int> unionArr;

        while(i < n && j < m) {
            // If both same, add once
            if(a[i] == b[j]) {
                if(unionArr.empty() || unionArr.back() != a[i])
                    unionArr.push_back(a[i]);
                i++;
                j++;
            }
            // If a[i] < b[j], add a[i]
            else if(a[i] < b[j]) {
                if(unionArr.empty() || unionArr.back() != a[i])
                    unionArr.push_back(a[i]);
                i++;
            }
            // If b[j] < a[i], add b[j]
            else {
                if(unionArr.empty() || unionArr.back() != b[j])
                    unionArr.push_back(b[j]);
                j++;
            }
        }
        // Remaining elements in a
        while(i < n) {
            if(unionArr.empty() || unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
        }
        // Remaining elements in b
        while(j < m) {
            if(unionArr.empty() || unionArr.back() != b[j])
                unionArr.push_back(b[j]);
            j++;
        }

        // Agar array return karna hota toh return unionArr;
        // Question me mostly count poocha hai, toh size return kar do:
        return unionArr.size();
    }
};
