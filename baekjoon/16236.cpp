#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 20
int map[MAX_N][MAX_N];
int result[MAX_N][MAX_N];
int isVisit[MAX_N][MAX_N];
int sharkSize = 2;
int fishNum = 0;
int N = 0;
int runningTime = 0;
int eat = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct coord {
    int x;
    int y;
    int distance;
};

coord sharkP;

struct compare {
    bool operator()(coord a, coord b) {
        if (a.distance < b.distance) {
            return false;
        } else if (a.distance == b.distance) {
            if (a.x < b.x) {
                return false;
            }
            else if (a.x == b.x) {
                if (a.y < b.y) return false;
                else return true;
            } else {
                return true;
            }
        } else {
            return true;
        }
    }
};

void initMap() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                sharkP = {i, j, 0}; //상어위치
                map[i][j] = 0;
            }
            else if (map[i][j]) ++fishNum; // 물고기 개수
        }
}

void initVisit() {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            isVisit[i][j] = 0;
        }
}

void BFS() {
    priority_queue<coord, vector<coord>, compare> q;
    q.push(sharkP);

    int cnt = 1;

    int i, nx, ny, dis=0;
    coord cur; // 현재위치

    while(!q.empty()) {
        cur = q.top(); q.pop();
        isVisit[cur.x][cur.y] = 1;

        nx = cur.x, ny = cur.y;

        if (map[nx][ny] && map[nx][ny] < sharkSize) {
            ++eat;
            --fishNum;
            map[nx][ny] = 0; // eat

            ++cnt;
            result[nx][ny] = cnt;

            runningTime += cur.distance; // 소요시간 추가

            if (eat == sharkSize) { // size up
                ++sharkSize;
                eat = 0;
            }
            sharkP = {nx, ny, 0}; // 상어위치 갱신

            if (!fishNum) return;

            // 새 위치에서 다시 시작
            while(!q.empty()) q.pop(); // q 비우기
            q.push(sharkP);
            initVisit();
            continue;
        }
        for (i=0; i<4; i++) {
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];

            if (nx<0 || nx>=N || ny<0 || ny>=N || isVisit[nx][ny]) continue; // outside or already visit
            if (map[nx][ny] > sharkSize) continue; // 지나칠 수 없음

            q.push({nx, ny, cur.distance+1}); // 계속 탐색
            isVisit[nx][ny] = 1;
        }
    }
}

int main() {
    initMap();
    BFS();
    printf("%d", runningTime);

//    printf("\n");
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) {
//            printf("%3d ", result[i][j]);
//        }
//        printf("\n");
//    }
    return 0;
}
