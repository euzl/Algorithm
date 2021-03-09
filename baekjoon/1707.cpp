#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int colors[20001];
vector<int> graph[20001];
void initColors(int v) {
    for (int i=1; i<=v; i++) colors[i] = 0;
}
void initGraph(int v) {
    for (int i=1; i<=v; i++)
        graph[i].clear();
}

/* 이거 풀이보고 작성 것!! 변수명 now, next 로 설정하는 센스 배우자 */
bool bfs(int start) {
    queue<int> q;
    q.push(start);
    colors[start] = 1;
    int now, next, color, gSize;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        color = colors[now]*(-1); // 현재와 반대색상
        gSize = graph[now].size();
        for (int i=0; i<gSize; i++) {
            next = graph[now][i];
            if (colors[next] == 0) {
                colors[next] = color; // 색칠
                q.push(next); // 다음번에 방문합시다
            } else if (colors[next] != color) {
                return false; // 더 할 것도 없이 이분그래프가 되지 못한
            }
        }
    }
    return true;
}

bool isBipatiteGraph(int v) {
    int gSize;
    for (int i=1; i<=v; i++) {
        gSize = graph[i].size();
        for (int j=0; j<gSize; j++) {
            if (colors[i] == colors[graph[i][j]]) return false;
        }
    }
    return true;
}

int main() {
    int k, v, e, a, b;
    scanf("%d", &k);
    bool isColored;
    while(k--) {
        isColored = false;
        scanf("%d %d", &v, &e);
        initColors(v);
        initGraph(v);
        for (int i=0; i<e; i++) {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i=1; i<=v; i++) {
            if (!colors[i]) isColored = bfs(i); // 방문전이라면 들려준다 ~
        }
        
        if (!isColored) {
            printf("NO\n");
        } else {
            if (isBipatiteGraph(v)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
