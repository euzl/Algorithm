#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int size;
vector<int> ju;
vector<int> dp[3];

void initJu() {
    scanf("%d", &size);

    int num;
    for (int j=0; j<size; j++) {
        scanf("%d", &num);
        ju.push_back(num);
    }
}

int main() {
    initJu();

    dp[0].push_back(0);
    dp[1].push_back(ju[0]);
    dp[2].push_back(ju[0]);

    for (int i=1; i<size; i++) {
        dp[0].push_back(max({dp[0][i-1], dp[1][i-1], dp[2][i-1]}));
        dp[1].push_back(dp[0][i-1] + ju[i]);
        dp[2].push_back(dp[1][i-1] + ju[i]);
    }

    printf("%d", max({dp[0][size-1], dp[1][size-1], dp[2][size-1]}));
    return 0;
}
