#include <cstdio>
#include <queue>
using namespace std;
#define MAX_SIZE 101
int R=0, C=0, M=0;
int A[MAX_SIZE][MAX_SIZE];
queue<int> waitList;
void print() {
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}
struct Shark {
    int r, c, s, d, z, idx;
    bool isDead;
    Shark() {r=0, c=0, s=0, d=0, z=0, isDead=false;}
    void set(int r, int c, int s, int d, int z, int idx) {this->r=r, this->c=c, this->s=s, this->d=d-1, this->z=z, this->idx=idx;}
    void setDead() {isDead = true;}
    void move() {
        A[r][c] = 0; // 기존 자리 지우기/

        // 새롭게 표시
        if (!A[r][c]) {
            A[r][c] = idx;
        } else {
            waitList.push(idx);
        }
    }
};
Shark shark[10002];


int main() {
    scanf("%d %d %d", &R, &C, &M);
    int r, c, s, d, z;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        shark[i+1].set(r,c,s,d,z,i+1);
        A[r][c] = i+1;
    }
    int result=0;
    for (int c=1; c<=C; c++) {
        for (int r=1; r<=R; r++) {
            if (A[r][c]) {
                result += shark[A[r][c]].z;
                shark[A[r][c]].setDead();
                A[r][c] = 0; // remove
                break;
            }
        }
        for (int i=1; i<=M; i++) {
            if(shark[i].isDead) continue;
            shark[i].move();
        }
        int idx, tr, tc, ex;
        while(!waitList.empty()) {
            idx = waitList.front(), waitList.pop();
            tr = shark[idx].r, tc = shark[idx].c;
            ex = A[tr][tc];
            if (shark[idx].z > shark[ex].z) {
                A[tr][tc] = idx;
                shark[ex].isDead = true;
            } else {
                shark[idx].isDead = true;
            }
        }
//        printf("\nC : %d\n", c);
//        print();
    }

    printf("%d", result);
    return 0;
}
