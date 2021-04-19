#include <cstdio>
#include <queue>
using namespace std;
#define MAX_SIZE 8
int map[MAX_SIZE][MAX_SIZE];
int isVisit[MAX_SIZE][MAX_SIZE];
int maxArea = -1;
int N=0, M=0;
int nxm=0;
//direction
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int wall[MAX_SIZE*MAX_SIZE];
void init() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            isVisit[i][j] = 0;
        }
    }
}

bool spreadVirus(pair<int, int> start) {
    int vCnt=0;
    queue<pair<int, int> > queue;
    queue.push(start);
    pair<int, int> cur;
    int x, y, nx, ny;
    while(!queue.empty()) {
        cur = queue.front(); queue.pop();
        x = cur.first, y = cur.second;
        ++vCnt;
        if (nxm-vCnt < maxArea) return false;
        for (int i=0; i<4; i++) {
            nx = x + dx[i], ny = y + dy[i];
            if (nx<0||nx>=N||ny<0||ny>=M) continue;
            if (isVisit[nx][ny]) continue;
            if (map[nx][ny] == 0) {
                queue.push({nx, ny});
                isVisit[nx][ny] = 2;
            }
        }
    }
    return true;
}
void count() {
    init();
    int c=0;
    for (int i=0; i<nxm; i++) {
        if (wall[i]) {
            isVisit[i/M][i%M] = 1;
            ++c;
            if(c==3) break;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 2) {
                if(!spreadVirus({i, j})) return; // not promising
            }
        }
    }
    int sum = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!map[i][j] && !isVisit[i][j]) {
                ++sum;
            }
        }
    }

    if (sum > maxArea) {
        maxArea = sum;
    }
}
void changeWall(int cnt, int start) {
    if (cnt == 3) {
        count();
        return;
    }
    for (int i=start; i<nxm-2+cnt; i++) {
        if (map[i / M][i % M] == 0) {
            wall[i] = 1; // set wall
            changeWall(cnt+1, i+1);
            wall[i] = 0;
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    nxm = N*M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    changeWall(0, 0);

    printf("%d", maxArea);
    return 0;
}
