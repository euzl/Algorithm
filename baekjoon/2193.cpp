#include <iostream>
using namespace std;

long long arr[2][2];

long long dp(int n) {
    arr[1][0] = 0;
    arr[1][1] = 1;
    for (int i=2; i<=n; i++) {
        arr[i%2][0] = arr[(i-1)%2][0] + arr[(i-1)%2][1];
        arr[i%2][1] = arr[(i-1)%2][0];
    }
    return arr[n%2][0] + arr[n%2][1];
}

int main() {
    int a = 0;
    cin >> a;
    cout << dp(a);
    return 0;
}
