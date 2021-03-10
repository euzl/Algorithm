#include <cstdio>
using namespace std;
int sun[1001];
int isVisit[1001];

void initArr(int n) {
    for (int i=1; i<=n; i++) {
        sun[i] = 0;
        isVisit[i] = 0;
    }
}
void DFS(int now) {
    if (!isVisit[now]) {
        isVisit[now] = 1;
        DFS(sun[now]);
    }
}
void calCount(int n) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (!isVisit[i]) {
            DFS(i);
            ++cnt;
        }
    }
    printf("%d\n", cnt);
}
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        initArr(n);
        // input
        for (int i=1; i<=n; i++) {
            scanf("%d", &sun[i]);
        }
        // find 순열 갯수
        calCount(n);
    }
    return 0;
}
