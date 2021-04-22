#include <cstdio>
//#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define MAX_N 51
int A[MAX_N][MAX_N];
int un[MAX_N][MAX_N];
int P[2600]; // 새 인구수
int N=0, L=0, R=0;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
bool isPossi;

void initUn() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            un[i][j] = 0;
        }
    }
}
bool bfs(pair<int, int> start, int color) {
    queue<pair<int, int> > q;
    q.push(start);
    un[start.first][start.second] = -1;
    int r, c, nr, nc, cnt=0, pop=0, dis;
    while(!q.empty()) {
        r = q.front().first, c = q.front().second, q.pop();

        for (int i=0; i<4; i++) {
            nr = r +  dr[i], nc = c + dc[i];
            if (nr<0||nr>=N||nc<0||nc>=N) continue;
            if (un[nr][nc]) continue;

            dis = abs(A[r][c] - A[nr][nc]);
            if (dis >= L && dis <= R) {
                ++cnt;
                pop += A[nr][nc];
                un[nr][nc] = color;
                q.push({nr, nc});
                isPossi = true;
            }
        }
    }
    un[start.first][start.second] = 0;
    if (cnt) {
        un[start.first][start.second] = color;
        pop += A[start.first][start.second];
        ++cnt;
        P[color] = pop/cnt;
        return true;
    } else {
        return false;
    }

}
void movePeople() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (un[i][j]) {
                A[i][j] = P[un[i][j]];
            }
        }
    }
}
void oneDay() {
    initUn(); // 연합해제.
    isPossi = false;

    // union
    int color=0;
    for (int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            if (!un[i][j]) {
                if (!bfs({i, j}, ++color)) --color;
            }
        }
    }
    if (isPossi) movePeople();
}
int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int i;
    for (i=0; i<=2000; i++) {
        oneDay();
        if (!isPossi) break;
    }
    printf("%d", i);

    return 0;
}
