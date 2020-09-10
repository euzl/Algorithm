#include <cstdio>
using namespace std;

int graph[1000][1000];
int visit[1000];

int dfs(int node, int size) {
    visit[node] = 1; // 들렸
    for(int i=0; i<size; i++) {
        if ((graph[node][i] != 0) && visit[i] != 1) {
            dfs(i, size);
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a,b;
    while(m--) {
        scanf("%d %d", &a, &b);
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    int sum = 0;
    for(int i=0; i<n; i++) {
        if (!visit[i]) {
            sum += dfs(i, n);
        }
    }
    printf("%d", sum);
}
