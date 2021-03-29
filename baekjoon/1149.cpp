#include <cstdio>
#include <algorithm>
using namespace std;

#define HOUSE_MAX_SIZE 1001
#define PRICE_MAX_SIZE 1000000
int dp[HOUSE_MAX_SIZE][3];

int getMinAroundColor(int i, int color) {
    int min = PRICE_MAX_SIZE;
    for (int c=0; c<3; c++) {
        if (c == color) continue; // pass same color
        if (dp[i-1][c] < min) min = dp[i-1][c];
    }
    return min;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] += getMinAroundColor(i, j);
        }
    }

    printf("%d\n", min({dp[N-1][0], dp[N-1][1], dp[N-1][2]}));

    return 0;
}
