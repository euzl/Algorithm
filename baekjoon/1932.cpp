#include <cstdio>
using namespace std;

int dp[501][502];
int n=0;

int getMax(int a, int b) { return a > b ? a : b; }
int main() {

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=1; j<=i+1; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<=i+1; j++) {
            dp[i][j] += getMax(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    int maxSum = -1;
    for (int k=1; k<=n; k++) {
        if (dp[n-1][k] > maxSum) maxSum = dp[n-1][k];
    }
    printf("%d", maxSum);
    return 0;
}
