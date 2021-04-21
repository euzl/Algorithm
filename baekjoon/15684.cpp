#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_N 13
#define MAX_H 33
int N=0, M=0, H=0;
int status[MAX_H][MAX_N];

bool possible() {
    int cur;
    for (int n=1; n<=N; n++) {
        cur = n;
        for (int h=1; h<=H; h++) {
            if (status[h][cur-1] == 1) {
                cur -=1;
            } else if (status[h][cur] == 1) {
                cur +=1;
            }
        }
        if (cur != n) return false;
    }
    return true;
}

void makeBridge(int hh, int cnt, int t) {
    if (cnt == t) {
        if (possible()) {
            printf("%d", cnt);
            exit(0);
        }
        return;
    }

    for (int h=hh; h<=H; h++) {
        for (int n = 1; n <= N; n++) {
            if (status[h][n] ||status[h][n - 1] ||status[h][n + 1]) continue;
            status[h][n] = 1;
            makeBridge(h, cnt + 1, t);
            status[h][n] = 0;
        }
    }
}

void find() {
    for (int t=1; t<=3; t++) {
        makeBridge(1, 0, t);
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &H);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        status[a][b] = 1;
    }
    if (possible()) {
        printf("0");
        return 0;
    }

    find();
    printf("-1");

    return 0;
}
