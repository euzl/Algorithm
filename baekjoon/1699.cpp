#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int dp[100001];
    for (int i=1; i<=n; i++) dp[i] = i; // 다 1^2의 합으로 초기화

    for (int i=2; i<=n; i++) {
        for (int j=2; j*j<=i; j++) {
            // 2^2 부터 빼준다. (이전 최소값 이용)
            dp[i] = min(dp[i], dp[i-j*j] + 1); // +1은 j*j가 추가되는 것 카운트
        }
    }

    printf("%d", dp[n]);
    return 0;
}
