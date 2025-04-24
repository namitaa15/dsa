bool static compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];  // Sort by end time
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;
    int prevEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < prevEnd) {
            count++;  // Overlapping → remove this interval
        } else {
            prevEnd = intervals[i][1];  // No overlap → move to next
        }
    }

    return count;
}
