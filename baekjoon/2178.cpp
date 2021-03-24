#include <cstdio>
#include <queue>
using namespace std;
int miro[100][100];
int isVisit[100][100];
int N, M;
int minimum = 10000; // 최댓값으로 초기
int row[4] = {-1,0,1,0};
int col[4] = {0,-1,0,1};

int getCount(int x, int y) {
    if (x==0 && y==0) return 1;

    int count = 10000;
    for (int i=0; i<4; i++) {
        int nx = x + row[i];
        int ny = y + col[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (isVisit[nx][ny] > 0 && isVisit[nx][ny] < count)
                count = isVisit[nx][ny];
        }
    }
    return count + 1;
}

void BFS() {
    queue<pair<int, int>> queue;
    queue.push({0, 0});

    while(!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop();
        int x = current.first;
        int y = current.second;
        if (isVisit[x][y]) continue;

        isVisit[x][y] = getCount(x, y);
        if (isVisit[x][y] > minimum) continue;
        if (x==N-1 && y==M-1) { // arrive
            minimum = isVisit[x][y];
        } else {
            for (int i=0; i<4; i++) {
                int nx = x + row[i];
                int ny = y + col[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && miro[nx][ny]) {
                    queue.push({nx, ny});
                }
            }
        }
    }

}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }
    BFS();
    printf("%d", minimum);

    return 0;
}
