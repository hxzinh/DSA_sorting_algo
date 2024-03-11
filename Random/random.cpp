#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double Random(double l, double r) {
    return uniform_real_distribution<double>(l, r)(rng);
}

const double MAX = 1e9;
double arr[1000005];

int main(int argc, char* argv[])
{
    string u = argv[1];
    string test = "test" + u + ".inp";
    freopen(test.c_str(), "w", stdout);
    std::srand(std::time(nullptr));

    int n = 1000000;
    cout << n << '\n';
    double pre = 0;
    for(int i = 0; i < n; i++) arr[i] = Random(10000.0, 1000000.0);

    if(argv[1] == "1") sort(arr, arr + n);
    if(argv[1] == "2") sort(arr, arr + n, greater<double>());

    for(int i = 0; i < n; i++)
        cout << fixed << setprecision(4) << arr[i] << " ";

    return 0;
}
