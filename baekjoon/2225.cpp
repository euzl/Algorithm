#include <cstdio>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    long dp[201] = {1, };

    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            dp[j] = (dp[j-1] + dp[j])%1000000000;
        }
    }
    printf("%ld", dp[n]);

    return 0;
}
