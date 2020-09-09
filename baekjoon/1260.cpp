#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
int dv[1000]; // 방문기록
int bv[1000];

void dfs(int n, int v) {
    cout << v+1 << ' '; // 도착했다!
    dv[v] = 1;
    for (int i=0; i<n; i++) {
        if (arr[v][i] && (dv[i] == 0)) {
            dfs(n, i);
        }
    }
}

void bfs(int n, queue<int> q) {
    int v;
    while(!q.empty()) {
        // arrive
        v = q.front();
        q.pop();

        if (bv[v]) continue;

        cout << v+1 << ' ';
        bv[v] = 1;

        // 대기열에 넣어준다.
        for (int i = 0; i < n; i++) {
            if (arr[v][i] && (bv[i] == 0)) {
                q.push(i);
            }
        }
    }
    return;
}
int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    int a, b;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        arr[a-1][b-1] = arr[b-1][a-1] = 1;
    }
    dfs(n, v-1);
    queue<int> q;
    q.push(v-1);
    cout<<endl;
    bfs(n, q);
    return 0;
}
