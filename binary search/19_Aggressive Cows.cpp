Problem Summary:
You are given a list of stall positions (unsorted).

You need to place k cows in the stalls such that the minimum distance between any two cows is maximum.

Return that maximum minimum distance.
  bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            cowsPlaced++;
            lastPos = stalls[i];
        }

        if (cowsPlaced == k) return true;
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;      // Try for a bigger minimum distance
            low = mid + 1;
        } else {
            high = mid - 1; // Try for a smaller one
        }
    }

    return ans;
}
