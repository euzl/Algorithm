#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
int count[101][101];
int n, m;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool isOut(int r, int c) {
    if (r<1||c<1||r>n||c>m||count[r][c]) return true;
    return false;
}
int BFS(vector<vector<int> > maps) {
    queue<pair<int, int>> q;
    q.push({1, 1}); count[1][1] = 1; // start position
    
    pair<int, int> cur;
    int nr, nc;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        for (int d=0; d<4; d++) {
            nr = cur.first + dr[d]; nc = cur.second + dc[d];
            if (isOut(nr, nc)) continue;
            if (!maps[nr-1][nc-1]) continue; // maps:[0,n)[0,m) count:[1,n][1,m]
            // printf("%d, %d\n", nr, nc);
            count[nr][nc] = count[cur.first][cur.second] + 1; // move 1
            if (nr == n && nc == m) return count[nr][nc]; // arrived at the opponent's camp
            q.push({nr, nc});
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = BFS(maps);
    return answer;
}
