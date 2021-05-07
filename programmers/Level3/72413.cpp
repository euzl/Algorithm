#include <string>
#include <queue>
#include <vector>

using namespace std;

#define NODE_MAX 201
int map[NODE_MAX][NODE_MAX];
int isVisit[NODE_MAX];
int minimum = 987654321;
int st;
int taxiFair;

void setMap(vector<vector<int>> fares) {
    for (vector<int> fare : fares) {
        map[fare[0]][fare[1]] = fare[2];
        map[fare[1]][fare[0]] = fare[2];
    }
}

void setMinimum(int n, int start, int dest) {
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (map[start][i]) q.push(i);
        isVisit[i] = 0;
    }
    int cur;
    int subFare = minimum;
    while(!q.empty()) { // 더이상 값의 변화가 없으면 stop
        cur = q.front(); q.pop();
        if(isVisit[cur]) continue;
        for (int i=1; i<=n; i++) {
            if (i == start) continue;
            if (map[cur][i]) {
                if (!map[start][i] || map[start][i] > map[start][cur] + map[cur][i]) {
                    int temp = map[start][cur] + map[cur][i];
                    map[start][i] = temp;
                    map[i][start] = temp;
                    if (i == dest) {
                        if (temp < subFare) subFare = temp;
                        continue;
                    }
                    if (temp > subFare) continue;
                    if (dest != 0 && taxiFair + subFare >= minimum) {
                        continue;
                    }
                    q.push(i); // next visit
                    isVisit[i] = 0;
                }
            }
        }
        isVisit[cur] = 1;
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    st = s;
    setMap(fares);
    setMinimum(n, s, 0);
    for (int i=1; i<=n; i++) {
        taxiFair = map[s][i];
        setMinimum(n, i, a);
        taxiFair += map[i][a];
        if (taxiFair >= minimum) continue;
        setMinimum(n, i, b);
        taxiFair += map[i][b];
        if (taxiFair >= minimum) continue;
        if (taxiFair) minimum = taxiFair;
    }

    return minimum;
}
