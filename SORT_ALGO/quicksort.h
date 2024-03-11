class QuickSort {
public:
    static void swap(double *a, double *b) {
        double c = *a;
        *a = *b;
        *b = c;
    }

    static int partition_pivot_last(double array[], int low, int high) {
        double pivot = array[high];
        int i = (low - 1);
 
        for(int j = low; j < high; j++) {
            if (array[j] < pivot)
                swap(&array[++i], &array[j]);
        }
 
        swap(&array[i + 1], &array[high]);
        return (i + 1);
    }

    static int Partition(double array[], int low, int high) {
        double pivot;
        int mid = (low + high) / 2;
        if (array[mid] < array[low]) 
            swap(&array[mid], &array[low]);
        if (array[high] < array[low])
            swap(&array[high], &array[low]);
        if (array[high] < array[mid])
            swap(&array[high], &array[mid]);

        swap(&array[mid], &array[high - 1]);
     
        pivot = array[high - 1];
     
        return partition_pivot_last(array, low, high);
    }

    static void quickSort(double arr[], int l, int r){
        if(l < r) {
            int id = Partition(arr, l, r);

            quickSort(arr, l, id - 1);
            quickSort(arr, id + 1, r);
        }
    }
};
