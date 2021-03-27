#include <cstdio>
#include <queue>
using namespace std;

#define INIT_MIN 100000

int map[100][100];
int isVisit[100][100];
int N=0;
int row[4] = {-1,0,1,0};
int col[4] = {0,-1,0,1};
int minBridge = INIT_MIN; // 도착섬을 포함한 다리길이

void colorBFS(int color, pair<int, int> start) { // 섬 색칠
    queue<pair<int, int>> queue;
    queue.push(start);

    pair<int, int> cur;
    while(!queue.empty()) {
        cur = queue.front();
        queue.pop();
        int x = cur.first;
        int y = cur.second;
        if (isVisit[x][y]) continue;

        isVisit[x][y] = 1;
        map[x][y] = color;

        for (int i=0; i<4; i++) {
            int nx = x + row[i];
            int ny = y + col[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny]) {
                queue.push({nx, ny});
            }
        }
    }
}

void coloring() { // 섬을 구분하기 위함
    int color = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] && !isVisit[i][j]) {
                colorBFS(++color, {i, j});
            }
        }
    }
}

void initVisit() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            isVisit[i][j] = 0;
        }
    }
}

int getMinimum(int x, int y) { // 경로의 최솟값 리턴
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            printf("%d ", isVisit[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    int minimum = INIT_MIN;
    for (int i=0; i<4; i++) {
        int nx = x + row[i];
        int ny = y + col[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !map[nx][ny] && isVisit[nx][ny]) {
            if (minimum > isVisit[nx][ny] + 1) minimum = isVisit[nx][ny] + 1;
        }
    }
//    if (minimum == INIT_MIN) minimum = 1;
    return minimum;
}

void bridgeBFS(pair<int, int> start, int color) {
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            printf("%d ", isVisit[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    initVisit();
    isVisit[start.first][start.second] = 1; // 시작지점! (건넌 다리 수 = 1)

    queue<pair<int, int>> queue;
    queue.push(start);
    pair<int, int> cur;

    while(!queue.empty()) {
        cur = queue.front();
        queue.pop();
        int x = cur.first;
        int y = cur.second;
        if (isVisit[x][y] > 1) continue;
        else if (!isVisit[x][y]) isVisit[x][y] = getMinimum(x, y);

        if (isVisit[x][y] > minBridge) continue; // 이미 최소는 물건너감

        if (map[x][y] && map[x][y] != color) { // 다른 섬
            if (isVisit[x][y] < minBridge) minBridge = isVisit[x][y];
//            printf("(%d, %d) %d ", x, y, minBridge);
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + row[i];
            int ny = y + col[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (map[nx][ny] == color) continue;

            // 지도 내에 있고, 다른 섬(color)일 때만
            queue.push({nx, ny});
        }
    }
}

void findBridge() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j]) {
                for (int d=0; d<4; d++) {
                    int nx = i + row[d];
                    int ny = j + col[d];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (map[nx][ny]) continue;

                    bridgeBFS({nx, ny}, map[i][j]);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    coloring();
    findBridge();

    printf("%d", minBridge-1);
    return 0;
}
