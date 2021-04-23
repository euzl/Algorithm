#include <cstdio>
#include <string.h>
using namespace std;
#define MAX_SIZE 4
struct Fish {
    int x, y, d, isLife; // 상어는 isLife를 먹은 물고기의 합으로 인식한다^^ 미안하다 물고기..
    void setCoord(int x, int y) { this->x=x, this->y=y;}
};
int A[MAX_SIZE][MAX_SIZE]; // index. shark=-1
Fish F[17];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int maxEat = -1;

void print(int map[][4]) {
    printf("\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
}

void printDirection(int map[][4], Fish fish[]) {
    printf("\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%3d", fish[map[i][j]].d);
        }
        printf("\n");
    }
}

void moveShark(Fish shark, Fish fish[], int map[][4], int maxP);
void moveFish(Fish shark, Fish fish[], int map[][4], int maxP) {
    if (shark.isLife + maxP < maxEat) return; // not promising

    Fish f[17] = {0, };
    memcpy(f, fish, sizeof(f));
    int m[4][4] = {0, };
    memcpy(m, map, sizeof(m));

    for (int i=1; i<=16; i++) {
        if (!f[i].isLife) continue;
        int maxD = f[i].d+8;
        int nx, ny, nd;
        for (int dir=f[i].d; dir<maxD; dir++) {
            nd = dir%8;
            nx=f[i].x+dx[nd], ny=f[i].y+dy[nd];
            if (nx<0||nx>=MAX_SIZE||ny<0||ny>=MAX_SIZE||m[nx][ny]==-1) continue;
            if(m[nx][ny]) {
                int idx = m[nx][ny];
                f[idx].setCoord(f[i].x, f[i].y);
                m[f[i].x][f[i].y] = m[nx][ny];
            } else {
                m[f[i].x][f[i].y] = 0;
            }
            m[nx][ny] = i; //cur
            f[i].setCoord(nx, ny);
            f[i].d = nd;
            break;
        }
    }
    moveShark(shark, f, m, maxP);
}
void moveShark(Fish shark, Fish fish[], int map[][4], int maxP) {
//    printf("\n\nShark start at (%d, %d)!! current: %d direction: %d\n", shark.x, shark.y, shark.isLife, shark.d);
//    print(map);
//    printDirection(map, fish);
    Fish f[17] = {0, };
    memcpy(f, fish, sizeof(f));
    int m[4][4] = {0, };
    memcpy(m, map, sizeof(m));
    m[shark.x][shark.y] = 0;

    int nx, ny, nd=shark.d;
    int cnt=0;
    for (int i=0; i<3; i++) {
        nx = shark.x+dx[nd], ny = shark.y+dy[nd];
        if (nx<0||nx>=MAX_SIZE||ny<0||ny>=MAX_SIZE) continue;
        shark.x=nx, shark.y=ny;
        if (!m[nx][ny]) continue;

        int idx = m[nx][ny];
        // eat
        m[nx][ny] = -1;
        f[idx].isLife = 0;
        moveFish({nx, ny, f[idx].d, shark.isLife + idx}, f, m, maxP-idx);

        // spit out
        m[nx][ny] = idx;
        f[idx].isLife = 1;
        ++cnt;
    }
    if (!cnt && shark.isLife > maxEat) {
//        printf("end(%d,%d) eat:%d\n", shark.x, shark.y, shark.isLife);
        maxEat = shark.isLife;
    }
}
int main() {
    int a, b;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d %d", &a, &b);
            A[i][j] = a;
            F[a] = {i, j, b-1, 1};
        }
    }
//    printDirection(A, F);
    int maxP = 136;
    // (0,0) eat
    Fish shark = {0, 0, F[A[0][0]].d, A[0][0]};
    F[A[0][0]].isLife = 0;
    maxP -= A[0][0];
    A[0][0] = -1;
    moveFish(shark, F, A, maxP);
    printf("%d", maxEat);
    return 0;
}
