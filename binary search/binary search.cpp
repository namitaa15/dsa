int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;  // Target found
        else if (nums[mid] < target)
            low = mid + 1;  // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    return -1;  // Target not found
}
