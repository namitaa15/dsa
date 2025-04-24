int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++; // Train arrives before previous departs
            i++;
        } else {
            platforms--; // One train departs → platform freed
            j++;
        }

        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}
