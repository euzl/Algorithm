#include <iostream>
using namespace std;
int map[500][500];
int isVisit[500][500];
int N = 0;
int out = 0;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };
void passMorae(int r, int c, int nr, int nc, int m) {
//    printf("movd to : %d, %d morae : %d\n", nr, nc, m);
    if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
        out += m;
        map[r][c] -= m;
        return;
    }
    map[nr][nc] += m;
    map[r][c] -= m;
}
void tonado(int r, int c, int d) {
//    printf("\n---R,C = %d, %d (%d)---\n", r, c, d);

    isVisit[r][c] = 1;
    int m = map[r][c];
    passMorae(r, c, r + dr[(d + 1) % 4] + dr[(d + 2) % 4], c + dc[(d + 1) % 4] + dc[(d + 2) % 4], m*0.01);
    passMorae(r, c, r + dr[(d + 2) % 4] + dr[(d + 3) % 4], c + dc[(d + 2) % 4] + dc[(d + 3) % 4], m*0.01);
    passMorae(r, c, r + dr[(d) % 4] + dr[(d + 3) % 4], c + dc[(d) % 4] + dc[(d + 3) % 4], m*0.1);
    passMorae(r, c, r + dr[(d) % 4] + dr[(d + 1) % 4], c + dc[(d) % 4] + dc[(d + 1) % 4], m*0.1);
    passMorae(r, c, r + dr[(d+3) % 4] + dr[(d + 3) % 4], c + dc[(d+3) % 4] + dc[(d + 3) % 4], m * 0.02);
    passMorae(r, c, r + dr[(d + 1) % 4] + dr[(d + 1) % 4], c + dc[(d + 1) % 4] + dc[(d + 1) % 4], m * 0.02);
    passMorae(r, c, r + dr[(d) % 4] + dr[(d) % 4], c + dc[(d) % 4] + dc[(d) % 4], m * 0.05);
    passMorae(r, c, r + dr[(d + 3) % 4], c + dc[(d + 3) % 4], m * 0.07);
    passMorae(r, c, r + dr[(d + 1) % 4], c + dc[(d + 1) % 4], m * 0.07);

//    printf("rest: %d d : %d\n", map[r][c], d);
    passMorae(r, c, r + dr[d], c+ dc[d], map[r][c]);

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("%3d ", map[i][j]);
//        }
//        printf("\n");
//    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>map[i][j];
        }
    }
    int d=3, nd;
    int r = N / 2, c = N / 2;
    while (1) {
        tonado(r, c, d);
        if (r == 0 && c == 0) break;
        // 좌표변경
        nd = (d + 1) % 4;
        if (!isVisit[r + dr[nd]][c + dc[nd]]) d = nd;
        r += dr[d], c += dc[d];
    }

    printf("%d", out);

    return 0;
}
