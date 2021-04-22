#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

enum Place { U, D, F, B, L, R };
int getPlace(char c) {
    switch(c){
        case 'U':
            return U;
        case 'D':
            return D;
        case 'F':
            return F;
        case 'B':
            return B;
        case 'L':
            return L;
        case 'R':
            return R;
    }
}
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
struct M {
    char cur[3][3];
    M* near[4]; // up, right, down, left
    int getNearD(M* call) {
        for (int i=0; i<4; i++) {
            if (near[i] == call) return i;
        }
    }
    void connect(M* u, M* r, M* d, M* l) {
        near[0] = u, near[1] = r, near[2] = d, near[3] = l;
    }
    void init(char c) {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cur[i][j] = c;
            }
        }
    }
    void rotateCur() {
        char rtemp[3][3];
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                rtemp[j][2-i] = cur[i][j];
            }
        }
        memcpy(cur, rtemp, sizeof(cur));
    }
    char* getNearCur(M* call) { // 시계방향!
        char* temp = new char[3];
        int d = getNearD(call);
        if (d == 0) {
            for (int i=0; i<3; i++) temp[i] = cur[0][2-i];
        } else if (d == 1) {
            for (int i=0; i<3; i++) temp[i] = cur[2-i][2];
        } else if (d == 2) {
            for (int i=0; i<3; i++) temp[i] = cur[2][i];
        } else if (d == 3) {
            for (int i=0; i<3; i++) temp[i] = cur[i][0];
        }
        return temp;
    }
    void setNearCur(char temp[], M* call) { // 시계방향!
        int d = getNearD(call);
        if (d == 0) {
            for (int i=0; i<3; i++) cur[0][2-i] = temp[i];
        } else if (d == 1) {
            for (int i=0; i<3; i++) cur[2-i][2] = temp[i];
        } else if (d == 2) {
            for (int i=0; i<3; i++) cur[2][i] = temp[i];
        } else if (d == 3) {
            for (int i=0; i<3; i++) cur[i][0] = temp[i];
        }
    }
    void turn(char dir) {
        int time = dir == '+' ? 1 : 3; // 시계 1번 반시계 3번 반
        char* temp = new char[3];
        for (int t=0; t<time; t++) {
            temp = near[3]->getNearCur(this);
            for (int i=3; i>0; i--) {
                near[i]->setNearCur(near[i-1]->getNearCur(this), this);
            }
            near[0]->setNearCur(temp, this);
            rotateCur();
        }
        delete temp;
    }
};
M cube[6];

void printTop() {
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%c", cube[U].cur[i][j]);
        }
        printf("\n");
    }
}

void connectCube() {
    cube[U].connect(&cube[B], &cube[R], &cube[F], &cube[L]);
    cube[D].connect(&cube[F], &cube[R], &cube[B], &cube[L]);
    cube[F].connect(&cube[U], &cube[R], &cube[D], &cube[L]);
    cube[B].connect(&cube[D], &cube[R], &cube[U], &cube[L]);
    cube[L].connect(&cube[U], &cube[F], &cube[D], &cube[B]);
    cube[R].connect(&cube[U], &cube[B], &cube[D], &cube[F]);
}

int main() {
    connectCube();
    int T;
    cin >> T;
    int n;
    char a, b;
    while(T--) {
        for (int i=0; i<6; i++) {
            cube[i].init(color[i]);
        }
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            cube[getPlace(a)].turn(b);
        }
        printTop();
    }

    return 0;
}
