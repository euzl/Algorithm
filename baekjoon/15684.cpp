#include <cstdio>
using namespace std;
#define MAX_N 13
#define MAX_H 33
int N=0, M=0, H=0;
int A[MAX_H][MAX_N];
int minn = 4;

bool ck() {
    int cur;
    for (int n=1; n<=N; n++) {
        cur = n;
        for (int h=1; h<=H; h++) {
            if (A[h][cur-1]) cur -=1;
            else if (A[h][cur]) cur +=1;
        }
        if (cur != n) return false;
    }
    return true;
}

void dfs(int cnt, int t) {
    if (minn != 4) return;
    if (cnt == t) {
        if (ck()) {
            if (minn > cnt) minn = cnt;
        }
        return;
    }
    for (int n = 1; n < N; n++) {
        for (int h=1; h<=H; h++) {
            if (A[h][n] ||A[h][n - 1] ||A[h][n + 1]) continue;
            A[h][n] = 1;
            dfs(cnt + 1, t);
            A[h][n] = 0;
            while(!A[h][n-1] && !A[h][n+1]) ++h; // 이 과정이 시간을 엄청 줄여준다!! (시간초과 -> 0ms)
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &H);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        A[a][b] = 1;
    }
    for (int t=0; t<=3; t++) {
        dfs(0, t);
        if (minn != 4) {
            printf("%d", minn);
            return 0;
        }
    }
    printf("-1");

    return 0;
}
