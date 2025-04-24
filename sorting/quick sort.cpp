int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot = last element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return pivot position
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // Sort left part
        quickSort(arr, pi + 1, high);  // Sort right part
    }
}
