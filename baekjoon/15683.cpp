#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
#define MAX_SIZE 8
int N=0, M=0;
int map[MAX_SIZE][MAX_SIZE];
vector<pair<int, int> > cctv_list;
int d[5] = {4, 2, 4, 4, 1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cctvCnt = 0;
int squareArea = 0;
void DFS(int cnt, int cctv[][MAX_SIZE], int rest);

bool isPromising(int nx, int ny) {
    if (nx<0||nx>=N||ny<0||ny>=M) return false;
    if (map[nx][ny] == 6) return false;
    return true;
}
void setArea(int cnt, int x, int y, int d, int c[][MAX_SIZE], int rest) {
    int cctv[MAX_SIZE][MAX_SIZE] = {0, };
    memcpy(cctv, c, sizeof(cctv));
    int nx = x + dx[d], ny = y + dy[d];

    if (map[x][y] == 1) {
        // -
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
    } else if (map[x][y] == 2) {
        // - -
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
        nx = x - dx[d], ny = y - dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx -= dx[d], ny -= dy[d];
        }
    } else if (map[x][y] == 3) {
        // ㄴ
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
        d = (d+1)%4;
        nx = x - dx[d], ny = y - dy[d];

        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx -= dx[d], ny -= dy[d];
        }
    } else if (map[x][y] == 4) {
        // ㅗ
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
        nx = x - dx[d], ny = y - dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx -= dx[d], ny -= dy[d];
        }
        d = (d+1)%4;
        nx = x + dx[d], ny = y + dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
    } else if (map[x][y] == 5) {
        // +
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
        nx = x - dx[d], ny = y - dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx -= dx[d], ny -= dy[d];
        }
        d = (d+1)%4;
        nx = x + dx[d], ny = y + dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx += dx[d], ny += dy[d];
        }
        nx = x - dx[d], ny = y - dy[d];
        while(isPromising(nx, ny)) {
            if (map[nx][ny] == 0 && cctv[nx][ny] == 0) {
                cctv[nx][ny] = 1;
                --rest;
            }
            nx -= dx[d], ny -= dy[d];
        }
    } else {
        return;
    }

    ++cnt;
    if (cnt == cctvCnt) {
        if (rest < squareArea) squareArea = rest;

//        printf("\n");
//        for (int i=0; i<N; i++) {
//            for (int j=0; j<M; j++) {
//                if (!map[i][j] && !cctv[i][j]) {
//                    printf("1 ");
//                } else {
//                    printf("0 ");
//                }
//            }
//            printf("\n");
//        }
        return;
    }
    DFS(cnt, cctv, rest);
}

void DFS(int cnt, int cctv[][MAX_SIZE], int rest) {
    int temp[MAX_SIZE][MAX_SIZE] = {0, };
    memcpy(temp, cctv, sizeof(temp));

    int x = cctv_list[cnt].first, y = cctv_list[cnt].second;

    if (map[x][y] > 0 && map[x][y] < 6 && !temp[x][y]) {
        // 가능한 경우의 수 만큼 탐색
        for (int k=0; k<d[map[x][y]-1]; k++) {
            setArea(cnt, x, y, k, temp, rest);
        }

    }
}


int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]>0 && map[i][j] < 6) {
                cctv_list.push_back({i, j});
                ++cctvCnt;
            }
            else if (map[i][j] == 0) {
                ++squareArea;
            }
        }
    }
    if (cctvCnt && squareArea) {
        int temp[MAX_SIZE][MAX_SIZE] = {0, };
        DFS(0, temp, squareArea);
    }

    printf("%d", squareArea);
    return 0;
}
