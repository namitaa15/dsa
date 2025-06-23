void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        swap(arr[start],arr[end]);
        // Move pointers
        start++;
        end--;
    }
}
