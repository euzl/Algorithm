#include <cstdio>
#include <cmath>
using namespace std;
#define MAX_SIZE 500
int N=0, M=0;
int map[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int answer = -1; // maximum value
int sx, sy;

void DFS(int bx, int by, int x, int y, int cnt, int sum) {
    if (x == sx && y == sy) return; // 시작지점이랑 일치하면 안됨.
    sum += map[x][y];
    ++cnt;
    if (cnt == 4) {
        if (answer < sum) {
            answer = sum;
        }
        return;
    }
    for (int d=0; d<4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx<0||nx>=N||ny<0||ny>=M) continue;
        if (nx==bx && ny == by) continue;

        DFS(x, y, nx, ny, cnt, sum);
    }
    
    // ㅗ ㅜ ㅓ ㅏ 처리
    if (cnt == 3) {
        if (bx == x && abs(y-by) == 1) {
            if (x+1 < N) DFS(x, y, x+1, by, cnt, sum);
            if (x-1 >= 0) DFS(x, y, x-1, by, cnt, sum);
        }
        if (by == y && abs(x-bx) == 1) {
            if (y+1 < N) DFS(x, y, bx, y+1, cnt, sum);
            if (y-1 >= 0) DFS(x, y, bx, y-1, cnt, sum);
        }
    }
}

int main() {
    answer = -1;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 0; d < 4; d++) {
                sx = i, sy = j;
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                DFS(i, j, nx, ny, 1, map[i][j]);
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}
