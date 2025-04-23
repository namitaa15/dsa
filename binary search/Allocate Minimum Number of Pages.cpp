Problem Summary:
You're given N books with pages in an array arr[], and M students.

Each book must be assigned to exactly one student.

Books must be assigned in order (contiguously).

Your task: Minimize the maximum pages assigned to a student

bool isPossible(vector<int>& arr, int M, int maxPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxPages)
            return false;  // A single book exceeds limit

        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
            if (students > M)
                return false;
        } else {
            pages += arr[i];
        }
    }

    return true;
}

int findPages(vector<int>& arr, int N, int M) {
    if (M > N) return -1;  // Not enough books

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, M, mid)) {
            result = mid;
            high = mid - 1;  // Try smaller max
        } else {
            low = mid + 1;   // Increase pages
        }
    }

    return result;
}
