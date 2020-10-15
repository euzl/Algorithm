#include <cstdio>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long dp[2][201];

    for (int i=0; i<=n; i++) dp[1][i] = 1;
    for (int i=2; i<=k; i++) {
        dp[i%2][0] = 1;
        for (int j=1; j<=n; j++) {
            dp[i%2][j] = (dp[i%2][j-1] + dp[(i+1)%2][j])%1000000000;
        }
    }
    printf("%ld", dp[k%2][n]);

    return 0;
}
