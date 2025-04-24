bool static compare(Job a, Job b) {
    return a.profit > b.profit; // Sort by descending profit
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> slot(maxDeadline + 1, -1);  // 1-based index
    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return {countJobs, jobProfit};
}
