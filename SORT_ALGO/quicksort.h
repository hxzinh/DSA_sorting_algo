class QuickSort {
public:
    static int Partition(double arr[], int l, int r, double pivot){
        int id = l;

        for(int i = l; i <= r; i++) {
            if(arr[i] <= pivot) {
                double cur = arr[i];
                arr[i] = arr[id];
                arr[id] = cur;
                id++;
            }
        }

        id--;
        return id;
    }

    static void quickSort(double arr[], int l, int r){
        if(l < r) {
            double pivot = arr[r];
            int id = Partition(arr, l, r, pivot);

            quickSort(arr, l, id - 1);
            quickSort(arr, id + 1, r);
        }
    }
};
