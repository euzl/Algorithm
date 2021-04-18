#include <cstdio>
#include <vector>
using namespace std;
#define MAX_SIZE 20

int N=0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int maxBlock = 0;
void calculateMax(vector<int> temp[]) {
//    printf("\n\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
//            printf("%4d ", temp[i][j]);
            if (temp[i][j] > maxBlock) {
                maxBlock = temp[i][j];
            }
        }
//        printf("\n");
    }
}
void initBoard(vector<int> board[]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i].push_back(0);
        }
    }
}
void DFS(vector<int> board[], int cnt, int d);
void moveHorizontal(vector<int> board[], int cnt, int d) {
    int dir = dx[d];
    vector<int> temp[MAX_SIZE];
    initBoard(temp);

    int i;
    int u;
    int idx;
    int isMove = 0;
    for (int j=0; j<N; j++) {
        if (dir == 1) { // up
            i=0;
        } else { // down
            i=N-1;
        }
        u = i+dir;
        idx = i;
        while (1) {
            // compare
            if (board[i][j] == 0) { // blank (i)
                i += dir, u += dir;
            } else {
                if (board[u][j] == 0) { // blank (u)
                    u += dir;
                } else if (board[i][j] == board[u][j]) { // same
                    temp[idx][j] = board[i][j]*2;
                    i = u + dir; // 바로 u의 다음 자리로 이동 ( 그 전은 다 blank )
                    u += dir*2;
                    idx += dir;
                    isMove = 1;
                } else { // not same
                    temp[idx][j] = board[i][j];
                    if (idx != i) {
                        isMove = 1;
                    }
                    i = u;
                    u += dir;
                    idx += dir;
                }
            }
            // end of board
            if (idx <= -1 || idx >= N || i <= -1 || i >= N) {
                break;
            }
            if (u <= -1 || u >= N) {
                temp[idx][j] = board[i][j];
                if (idx != i) {
                    isMove = 1;
                }
                break;
            }
        }
    }
    cnt += isMove;
    if (isMove == 0 || cnt == 5) {
        calculateMax(temp);
        return;
    }

    DFS(temp, cnt, d);
}


void moveVertical(vector<int> board[], int cnt, int d) {
    int dir = dy[d];
    vector<int> temp[MAX_SIZE];
    initBoard(temp);

    int i;
    int u;
    int idx;
    int isMove = 0;
    for (int j=0; j<N; j++) {
        if (dir == 1) { // right
            i=0;
        } else { // left
            i=N-1;
        }
        u = i+dir;
        idx = i;
        while (1) {
            // compare
            if (board[j][i] == 0) { // blank (i)
                i += dir, u += dir;
            } else {
                if (board[j][u] == 0) { // blank (u)
                    u += dir;
                } else if (board[j][i] == board[j][u]) { // same
                    temp[j][idx] = board[j][i]*2;
                    i = u + dir; // 바로 u의 다음 자리로 이동 ( 그 전은 다 blank )
                    u += dir*2;
                    idx += dir;
                    isMove = 1;
                } else { // not same
                    temp[j][idx] = board[j][i];
                    if (idx != i) {
                        isMove = 1;
                    }
                    i = u;
                    u += dir;
                    idx += dir;
                }
            }
            // end of board
            if (idx <= -1 || idx >= N || i <= -1 || i >= N) {
                break;
            }
            if (u <= -1 || u >= N) {
                temp[j][idx] = board[j][i];
                if (idx != i) {
                    isMove = 1;
                }
                break;
            }
        }
    }
    cnt += isMove;
    if (isMove == 0 || cnt == 5) {
        calculateMax(temp);
        return;
    }

    DFS(temp, cnt, d);
}

void DFS(vector<int> board[], int cnt, int d) {
    for (int dr=0; dr<4; dr++) {
//        if (d == dr) continue;
        if (dy[dr]==0) moveHorizontal(board, cnt, dr);
        else moveVertical(board, cnt, dr);
    }
}

int main() {
    vector<int> board[MAX_SIZE];
    scanf("%d", &N);

    int n;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &n);
            board[i].push_back(n);
        }
    }
    if (N == 1) {
        printf("%d", n);
        return 0;
    }
    DFS(board, 0, -1);
    printf("%d", maxBlock);
    return 0;
}
