#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define NODE_SIZE 100001
vector<int> tree[NODE_SIZE];
int parent[NODE_SIZE] = {1, 1, };

void findParent(int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : tree[cur]) {
            if (parent[next]) continue;
            parent[next] = cur;
            q.push(next);
        }
    }

}
int main() {
    int N;
    scanf("%d", &N);
    int n1, n2;
    for (int i=1; i<N; i++) {
        scanf("%d %d", &n1, &n2);
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    findParent(1);

    for (int i=2; i<=N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}
