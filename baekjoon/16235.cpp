#include <cstdio>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
#define MAX_N 11
int N=0, M=0, K=0;
int dr[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dc[8] = {0, 1, 0, -1, 1, -1, -1, 1};
queue<pair<int, int> > bList;
struct D{
    int r, c;
    int yb; // 양분.
    int a; // input A
    int treeCnt;
    int fiveCnt;
    deque<int> tree; // age 순서대로 저장됨.
    D() {
        yb = 5;
        treeCnt = 0;
        fiveCnt = 0;
    }
    void init(int r, int c, int a) {this->r = r, this->c = c, this->a = a; }
    void addTree(int age) { tree.push_front(age), ++treeCnt; }
    void ss() {
        // spring
        int i;
        for (i=0; i<treeCnt; i++) {
            if (tree.at(i) <= yb) {
                yb -= tree.at(i); // yb ate
                ++tree.at(i); // age up
                if (tree.at(i)%5 == 0) ++fiveCnt;
            } else {
                break;
            }
        }
        // summer
        int death = treeCnt - i;
        while(death--) {
            yb += tree.back()/2;
            tree.pop_back();
        }
        treeCnt = tree.size();

        // fall
        while(fiveCnt) {
            int nr, nc;
            for (int j=0; j<8; j++) {
                nr = r + dr[j], nc = c + dc[j];
                if (nr<0||nr>=N||nc<0||nc>=N) continue;
                bList.push({nr, nc});
            }
            --fiveCnt;
        }
    }
    void winter() { yb += a;}
};
D map[MAX_N][MAX_N];

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int a;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &a);
            map[i][j].init(i, j, a);
        }
    }
    int x, y, z;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &x, &y, &z);
        map[x-1][y-1].addTree(z);
    }

    for (int i=0; i<K; i++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                map[i][j].ss();
            }
        }
        int r, c;
        while(!bList.empty()) { // fall
            r=bList.front().first, c=bList.front().second, bList.pop();
            map[r][c].addTree(1);
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                map[i][j].winter();
            }
        }
    }

    int sum=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sum += map[i][j].treeCnt;
        }
    }
    printf("%d", sum);

    return 0;
}
