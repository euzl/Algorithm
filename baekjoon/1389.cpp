#include <cstdio>
using namespace std;
#define USER_MAX 101
bool isVisit[USER_MAX];
int dp[USER_MAX][USER_MAX];
int userNum = 0;
int relationNum = 0;

void initVisit() {
    for (int i=1; i<userNum+1; i++) isVisit[i] = false;
}

int getMinIndex(int node) {
    int idx = -1;
    int min = USER_MAX;
    for (int i=1; i<userNum+1; i++) {
        if (isVisit[i]) continue;
        if (dp[node][i] && dp[node][i]<min) {
            min = dp[node][i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int node) {
    initVisit();
    int fNode;
    isVisit[node] = true;
    while(1) {
        fNode = getMinIndex(node);
        if (fNode == -1) break;
        isVisit[fNode] = true;
        for (int n=1; n<userNum+1; n++) {
            if (dp[fNode][n]) {
                if (!dp[node][n] || dp[node][fNode] + dp[fNode][n] < dp[node][n]) {
                    dp[node][n] = dp[node][fNode] + dp[fNode][n];
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &userNum, &relationNum);
    int a, b;
    for (int i=0; i<relationNum; i++) {
        scanf("%d %d", &a, &b);
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    int userIdx;
    int userMin = USER_MAX;
    for (int i=1; i<=userNum; i++) {
        dijkstra(i);
        int userSum = 0;
        for (int j=1; j<=userNum; j++) {
            userSum += dp[i][j];
        }
        if (userSum < userMin) {
            userMin = userSum;
            userIdx = i;
        }
    }
    printf("%d", userIdx);
    return 0;
}
