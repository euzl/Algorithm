#include <cstdio>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int dp[31] = {1, 0, 3, };

    if (n%2 == 0) {
        for (int i=4; i<=n; i += 2) {
            dp[i] = dp[i-2]*3; // 2타일 추가시 3가직 경우의 수 추가 (맨 오른쪽에 추가한다고 가정)

            for (int j=0; i-j >= 4; j += 2) {
                // 4타일이 추가될 때마다 2가지 경우의 수가 추가됨 (엄청 길다란,,)
                // dp[0]은 없지만, 아무것도 없을 때에도 2가지가 추가되므로 dp[0]==1
                dp[i] += dp[j]*2;
            }
        }
    }

    printf("%d", dp[n]);
    return 0;
}
