#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_SIZE 51
pair<int, int> A[MAX_SIZE][MAX_SIZE];
pair<int, int> gc[2];
int R=0, C=0, T=0;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

void print() {
    printf("\n");
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            printf("%2d ", A[i][j].first);
        }
        printf("\n");
    }
}

void hwaksan() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (A[i][j].first <= 0) continue;
            int give = A[i][j].first/5;
            for (int k=0; k<4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr<0||nr>=R||nc<0||nc>=C||A[nr][nc].first==-1) continue;
                A[nr][nc].second += give;
                A[i][j].first -= give;
            }
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (A[i][j].second <= 0) continue;
            A[i][j].first += A[i][j].second;
            A[i][j].second = 0;
        }
    }
}
void ggcleaner() {
    int r, c, nr, nc, d;
    // up
    r = gc[0].first, c = gc[0].second, d = 1;
    r = r+dr[d], c = c+dc[d];
    while(1) {
        nr = r+dr[d], nc = c+dc[d];
        if (nr<0||nr>=gc[1].first||nc<0||nc>=C) {
            d = (d+3)%4;
            continue;
        }
        if (A[nr][nc].first == -1) {
            A[r][c].first = 0;
            break;
        }
        A[r][c].first = A[nr][nc].first;
        r=nr, c=nc;
    }

    // down
    r = gc[1].first, c = gc[1].second, d = 3;
    r = r+dr[d], c = c+dc[d];
    while(1) {
        nr = r+dr[d], nc = c+dc[d];
        if (nr<gc[1].first||nr>=R||nc<0||nc>=C) {
            d = (d+1)%4;
            continue;
        }
        if (A[nr][nc].first == -1) {
            A[r][c].first = 0;
            break;
        }
        A[r][c].first = A[nr][nc].first;
        r=nr, c=nc;
    }
}
int main() {
    scanf("%d %d %d", &R, &C, &T);
    int input;
    int gccnt=0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%d", &input);
            A[i][j].first = input;
            if (input == -1) gc[gccnt++] = {i, j};
        }
    }
//    print();
    for (int t=0; t<T; t++) {
        hwaksan();
//        print();
        ggcleaner();
//        print();
    }

    int sum=0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (A[i][j].first > 0) sum += A[i][j].first;
        }
    }
    printf("%d", sum);

    return 0;
}
