#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define K_MAX 1000000

int main() {
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    int dp[100001] = {0, }; // 개수저장 (동전의 최대 가치 크기 주의!!)
    vector<int> coin;
    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        coin.push_back(num);
        dp[num] = 1;
    }

    // 정렬하고 중복제거
    sort(coin.begin(), coin.end());
    coin.erase(unique(coin.begin(), coin.end()), coin.end());

    for (int i=1; i<coin[0]; i++) dp[i] = -1;
    for (int i=coin[0]; i<=k; i++) {
        if (dp[i] > 0) continue;
        dp[i] = K_MAX;
        for (int j=0; j<n; j++) {
            if (coin[j] > i) break;
            if (dp[i-coin[j]] == -1) continue;
            dp[i] = min(dp[i], dp[i-coin[j]] + dp[coin[j]]);
        }
        if (dp[i] >= K_MAX) dp[i] = -1;
    }
    
    printf("%d", dp[k]);
    return 0;
}
