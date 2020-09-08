#include <iostream>
using namespace std;

#define MOD 1000000000

int arr[2][12];

int stair(int n) {
    int ans = 9;
    for (int i = 2; i < 11; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        ans = 0;
        for (int j=1; j<11; j++) {
            arr[i%2][j] = (arr[(i-1)%2][j-1] + arr[(i-1)%2][j+1])%MOD;
            ans = (ans + arr[n%2][j])%MOD;
        }
    }
    return ans;
}

int main() {
    int a = 0;
    cin >> a;
    cout << stair(a);
    return 0;
}
