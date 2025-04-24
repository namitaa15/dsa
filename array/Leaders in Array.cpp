vector<int> leaders(int arr[], int n) {
    vector<int> result;
    int maxRight = arr[n - 1];
    result.push_back(maxRight);  // Last element is always a leader

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            result.push_back(arr[i]);
        }
    }

    reverse(result.begin(), result.end());  // To maintain original order
    return result;
}
