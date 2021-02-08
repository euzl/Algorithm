#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    long long *arr = new long long[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cout << arr[k-1];

    delete arr;

    return 0;
}
