#include <iostream>
using namespace std;

#define MOD 10007

int arr[2][11];

int stair(int n) {
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j=9; j>=0; j--) {
            arr[i%2][j] = (arr[(i-1)%2][j] + arr[i%2][j+1]) % MOD;
        }
    }

    for (int j=0; j<10; j++) {
        ans = (ans + arr[n%2][j]) % MOD;
    }
    return ans;
}

int main() {
    int a = 0;
    cin >> a;
    cout << stair(a);
    return 0;
}
