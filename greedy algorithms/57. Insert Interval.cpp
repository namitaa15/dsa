class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& ni) {
        vector<vector<int>> ans;
        int n = intervals.size();
        intervals.push_back(ni);
        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (currentInterval[1] >= intervals[i][0]) {
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        ans.push_back(currentInterval);
        return ans;
    }
};
