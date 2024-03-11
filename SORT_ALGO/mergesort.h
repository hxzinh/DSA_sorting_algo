class MergeSort {

public:
    static void mergeArr(double arr[], int const left, int const mid, int const right) {
        int const subarrOne = mid - left + 1;
        int const subarrTwo = right - mid;

        // Create temp arrs
        auto *leftarr = new double[subarrOne],
             *rightarr = new double[subarrTwo];

        // Copy data to temp arrs leftarr[] and rightarr[]
        for (int i = 0; i < subarrOne; i++)
            leftarr[i] = arr[left + i];
        for (int j = 0; j < subarrTwo; j++)
            rightarr[j] = arr[mid + 1 + j];

        auto indexOfSubarrOne = 0, indexOfSubarrTwo = 0;
        int indexOfMergedarr = left;

        // Merge the temp arrs back into arr[left..right]
        while (indexOfSubarrOne < subarrOne
               && indexOfSubarrTwo < subarrTwo) {
            if (leftarr[indexOfSubarrOne]
                <= rightarr[indexOfSubarrTwo]) {
                arr[indexOfMergedarr]
                    = leftarr[indexOfSubarrOne];
                indexOfSubarrOne++;
            }
            else {
                arr[indexOfMergedarr]
                    = rightarr[indexOfSubarrTwo];
                indexOfSubarrTwo++;
            }
            indexOfMergedarr++;
        }

        while (indexOfSubarrOne < subarrOne) {
            arr[indexOfMergedarr]
                = leftarr[indexOfSubarrOne];
            indexOfSubarrOne++;
            indexOfMergedarr++;
        }

        while (indexOfSubarrTwo < subarrTwo) {
            arr[indexOfMergedarr]
                = rightarr[indexOfSubarrTwo];
            indexOfSubarrTwo++;
            indexOfMergedarr++;
        }
        delete[] leftarr;
        delete[] rightarr;
    }

    static void mergeSort(double arr[], int const l, int const r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeArr(arr, l, mid, r);
    }

};
