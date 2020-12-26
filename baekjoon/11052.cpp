#include <iostream>
using namespace std;

int main() {
    int dp[1001];
    int num = 0;
    cin >> num;
    for (int i=1; i<=num; i++) {
        cin >> dp[i];
    }

    for (int i=2; i<=num; i++) {
        for (int j=1; j<=i/2; j++) {
            if (dp[i] >= dp[j] + dp[i-j]) {
                continue;
            }
            dp[i] = dp[j] + dp[i-j];
        }
    }
    cout << dp[num];
    return 0;
}
