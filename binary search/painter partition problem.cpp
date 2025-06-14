#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& boards, int n, int k, int maxUnits) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxUnits) return false;

        if (currSum + boards[i] > maxUnits) {
            painters++;
            currSum = boards[i];
        } else {
            currSum += boards[i];
        }
    }

    return painters <= k;
}

int painterPartition(vector<int>& boards, int n, int k) {
    if (k > n) return -1;

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Example usage:
// vector<int> boards = {10, 20, 30, 40};
// int n = boards.size();
// int k = 2;
// cout << painterPartition(boards, n, k); // Output: 60
