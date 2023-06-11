int search(int* arr, int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;  // Key found at mid index

        if (arr[start] <= arr[mid]) {
            if (arr[start] <= key && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if (arr[mid] < key && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}
