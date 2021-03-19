#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define BOX_SIZE 1000
int box[BOX_SIZE][BOX_SIZE]; // 0 안익 1 익
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};
int day; // 며칠 지났는지
int M, N;
int rest; // 나머지 개수
int tomato; // 익은거 개수
void init(queue<pair<int, int>> &q) {
    scanf("%d %d", &M, &N);
    rest = 0;
    day = 0;
    tomato = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 0) ++rest;
            else if (box[i][j] == 1) {
                ++tomato;
                q.push({i, j});
            }
        }
    }
}

void BFS() {
    queue<pair<int, int>> q;
    init(q);
    if (!rest) {
        printf("0");
        return;
    }

    pair<int, int> cur;

    int x, y;
    int nextTomato = 0;
    while(!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            x = cur.first + col[i];
            y = cur.second + row[i];
            if (x >= 0 && x < N && y >= 0 && y < M) {
                if (box[x][y] == 0) {
                    q.push({x, y});
                    box[x][y] = 1; // 익는
                    --rest;
                    ++nextTomato;
                }
            }
        }
        --tomato;
        if (tomato == 0) {
            ++day;
            tomato = nextTomato;
            nextTomato = 0;
        }
    }
    if (rest == 0) printf("%d", day-1);
    else printf("-1");
}

int main() {
    BFS();
    return 0;
}
