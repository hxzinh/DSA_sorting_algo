class HeapSort {
public:
    static void heapify(double arr[], int n, int i) {
        int id = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[id]) id = l;
        if (r < n && arr[r] > arr[id]) id = r;

        if (id != i) {
            double cur = arr[i];
            arr[i] = arr[id];
            arr[id] = cur;
            heapify(arr, n, id);
        }
    }

    static void heapSort(double arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

        for (int i = n - 1; i >= 0; i--) {
            double cur = arr[i];
            arr[i] = arr[0];
            arr[0] = cur;
            heapify(arr, i, 0);
        }
    }
};
