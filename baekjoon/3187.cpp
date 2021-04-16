#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX_SIZE 251
string map[MAX_SIZE];
bool isVisit[MAX_SIZE][MAX_SIZE];

int R=0, C=0;
int v_sum = 0, k_sum=0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void initVisit() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            isVisit[i][j] = false;
        }
    }
}

void BFS(int sx, int sy) {
//    initVisit();
    isVisit[sx][sy] = true;
    int k_cnt = 0, v_cnt = 0;

    queue<pair<int, int> > q;
    q.push({sx, sy});

    pair<int, int> cur;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        if (map[x][y] == 'v') ++v_cnt;
        else if (map[x][y] == 'k') ++k_cnt;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=R || ny < 0 || ny >= C) continue;
            if (isVisit[nx][ny] || map[nx][ny] == '#') continue;

            q.push({nx, ny});
            isVisit[nx][ny] = true;
        }
    }
    if (k_cnt > v_cnt) k_sum += k_cnt;
    else v_sum += v_cnt;
}

int main() {
    scanf("%d %d\n", &R, &C);

    for (int i=0; i<R; i++) {
        cin >> map[i];
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (!isVisit[i][j] && map[i][j] != '#') BFS(i, j);
        }
    }

    printf("%d %d", k_sum, v_sum);

    return 0;
}
