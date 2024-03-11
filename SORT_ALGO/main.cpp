#include <bits/stdc++.h>
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

int n;
double a[1000005];

bool check() {
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int T = 0; T < 10; T++) {
        string cur = "";
        cur += char(T + 49);
        string test = "test" + ((T == 9) ? "10" : cur) + ".inp";
        cout << test << " ";
        freopen(test.c_str(), "r", stdin);
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];

        auto staTime = high_resolution_clock::now();
        QuickSort::quickSort(a, 0, n - 1);
        //MergeSort::mergeSort(a, 0, n);
        //HeapSort::heapSort(a, n);
        //sort(a, a + n);
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(endTime - staTime);

        if(check()) cout << "Correct!!! ";
        else cout << "Wrong!!! ";
        cout << duration.count() << "ms" << '\n';
    }
    return 0;
}
