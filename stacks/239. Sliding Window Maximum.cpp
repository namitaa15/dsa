vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove smaller values from back of deque
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Window starts forming after first k-1 elements
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
