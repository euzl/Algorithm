#include <cstdio>
using namespace std;
int N=0, M=0;
#define MAX_SIZE 50
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX_SIZE][MAX_SIZE];
int isClean[MAX_SIZE][MAX_SIZE];
int cleanCnt=0;
bool DFS(int x, int y, int d) {
    bool isPosi = false;
    if (!isClean[x][y]) {
        ++cleanCnt;
        isClean[x][y] = cleanCnt;
    }
//    printf("cnt %d d %d\n", isClean[x][y], d);
    int nx, ny, nd;
    for (int i=3; i>=0; i--) {
        nd = (d+i)%4;
        nx = x+dx[nd];
        ny = y+dy[nd];
        if (nx<0||nx>=N||ny<0||ny>=M) continue;
        if (!map[nx][ny] && !isClean[nx][ny]) {
            if (!DFS(nx, ny, nd)) return false;
            isPosi = true;
        }
    }
    if (!isPosi) {
        nx = x-dx[d];
        ny = y-dy[d];
        if (nx>=0 && nx<N && ny>=0 && ny<M) {
            if (map[nx][ny]) return false;
            if (!DFS(nx, ny, d)) return false;
        }
    }
    return true;
}
int main() {
    int r,c,d;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    DFS(r, c, d);
    printf("%d", cleanCnt);

//    printf("\n");
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<M; j++) {
//            printf("%3d", isClean[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
