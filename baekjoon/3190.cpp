#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 101

vector<pair<int, char> > dInfo;
int apple[MAX_N][MAX_N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N=0, L=0;

struct Snake{
    int x, y, length, lifeTime, direction;
    int body[MAX_N][MAX_N];

    Snake() {
        x=1, y=1, length=1, lifeTime=0, direction=0;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                body[i][j] = 0;
        body[x][y] = 1;
    }
    void clock() { // 1초 지날 때 마다 길이 줄이기 ~~ (사과 안 먹었을 때만)
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (body[i][j]) --body[i][j];
            }
        }
    }
    void rotate(char C) {
        if (C == 'L') direction = (direction+3)%4;
        else direction = (direction+1)%4;
    }
    bool isOver() {
        if (x < 1 || x > N || y < 1 || y > N) return true;
        if (body[x][y]) return true;
        return false;
    }
    void move() {
        int dIdx = 0;
        while(1) {
            if (L > dIdx && lifeTime == dInfo[dIdx].first) {
                rotate(dInfo[dIdx].second);
                ++dIdx;
            }
            x += dx[direction], y += dy[direction];
            ++lifeTime;
            if (isOver()) {
                printf("%d", lifeTime);
                break;
            }
            ++length;
            body[x][y] = length;
            if (!apple[x][y]) {
                clock();
                --length;
            } else {
                apple[x][y] = 0;
            }
        }

    }
};

int main() {
    scanf("%d", &N);
    Snake s;
    int K, ax, ay;
    scanf("%d", &K);
    for (int i=0; i<K; i++) {
        scanf("%d %d", &ax, &ay);
        apple[ax][ay] = 1;
    }
    int X;
    char C;
    scanf("%d", &L);
    for (int i=0; i<L; i++) {
        scanf("%d %1c", &X, &C);
        dInfo.push_back({X, C});
    }
    s.move();

    return 0;
}
