#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int map[27][27]; // 1집 0빈집&들린집
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};
int danji[330]; // 단지별 인원수 저장?
int cnt; // 현재 몇단지인지
int N;


void BFS(pair<int, int> start) {
    if(map[start.first][start.second] == 0) return;
    queue<pair<int, int>> q;
    q.push(start);

    pair<int, int> cur;
    ++cnt;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if (map[cur.first][cur.second] == 0) continue;
        map[cur.first][cur.second] = 0; // 확인완료했으니 지우
        ++danji[cnt];
        for(int i=0; i<4; i++) {
            if (cur.first+row[i] >=0 && cur.first+row[i] <N) {
                if (cur.second+col[i] >= 0 && cur.second+col[i] < N) {
                    if (map[cur.first+row[i]][cur.second+col[i]]) {
                        q.push({cur.first+row[i],cur.second+col[i]});
                    }
                }
            }
        }
    }
}

int main() {
    cnt=0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &map[i][j]); // 한개씩 입력
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            BFS({i,j});
        }
    }
    sort(danji+1, danji+cnt+1);
    printf("%d\n", cnt);
    for (int i=1; i<=cnt; i++) printf("%d\n", danji[i]);
    return 0;
}
