#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
#define MAX_N 102
int a[MAX_N][MAX_N];
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, -1, 0, 1};
int N=0;

void printCount() {
    int count = 0;
    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            if (a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]) ++count;
        }
    }
    printf("%d", count);
}

vector<int> getInfo(int g, int d) {
    stack<int> stack;
    vector<int> q;
    q.push_back(d);
    for (int i=0; i<g; i++) {
        int size = q.size();
        for (int j=0; j<size; j++) {
            stack.push(q[j]);
        }
        while(!stack.empty()) {
            q.push_back((stack.top() + 1)%4);
            stack.pop();
        }
    }
//    for (int i : q) {
//        printf("%d ", i);
//    }
//    printf("\n");
    return q;
}

void drawMap(int r, int c, vector<int> gInfo) {
    int d, nr=r, nc=c;
    a[nr][nc] = 1;
    int size = gInfo.size();
    for (int i=0; i<size; i++) {
        d = gInfo[i];
        nr += dr[d], nc += dc[d];
        a[nr][nc] = 1;
    }
}

int main() {
    scanf("%d", &N);

    int x, y, d, g;
    for (int i=0; i<N; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        drawMap(y, x, getInfo(g, d));
    }
    printCount();
    return 0;
}
