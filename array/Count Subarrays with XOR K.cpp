int countSubarraysWithXorK(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int count = 0, xorSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        xorSum ^= arr[i];

        if (xorSum == k) count++;

        if (freq.find(xorSum ^ k) != freq.end())
            count += freq[xorSum ^ k];

        freq[xorSum]++;
    }

    return count;
}
