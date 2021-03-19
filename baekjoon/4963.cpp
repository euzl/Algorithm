#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int map[52][52]; // 1땅 / 0바다, 들림
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};
int cnt; // 현재 몇단지인지
int w, h;

void BFS(pair<int, int> start) {
    if(map[start.first][start.second] == 0) return;
    queue<pair<int, int>> q;
    q.push(start);

    pair<int, int> cur;
    ++cnt;

    int x, y;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if (map[cur.first][cur.second] == 0) continue;
        map[cur.first][cur.second] = 0; // 확인완료했으니 지우
        // 직선
        for (int i = 0; i < 4; i++) {
            x = cur.first + row[i];
            y = cur.second + col[i];
            if (x >= 0 && x < h && y >= 0 && y < w) {
                if (map[x][y]) {
                    q.push({x, y});
                }
            }
        }
        // 대각
        for (int i = 0; i < 3; i += 2) {
            for (int j = 1; j<4; j += 2) {
                x = cur.first + row[i];
                y = cur.second + col[j];
                if (x >= 0 && x < h && y >= 0 && y < w) {
                    if (map[x][y]) {
                        q.push({x, y});
                    }
                }
            }
        }
    }
}

int main() {
    while(1) {
        cnt=0;
        scanf("%d %d", &w, &h);
        if (w==0 && h == 0) break;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                scanf("%d", &map[i][j]); // 한개씩 입력
            }
        }
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                BFS({i,j});
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
