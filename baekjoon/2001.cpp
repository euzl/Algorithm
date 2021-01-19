#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ISLAND_MAX 101

int n, m, k;
int bridge[ISLAND_MAX][ISLAND_MAX]; // 연결 다리
bool jewel[ISLAND_MAX]; // 보석 존재 여부
bool visit[ISLAND_MAX]; // 방문한 섬 체크
int maxRoute[ISLAND_MAX]; // 최대 견딜 수 있는 보석 수

int getMax(int a, int b) {
    if (a > b) return a;
    else return b;
}

int getMin(int a, int b) {
    if (a < b) return a;
    else return b;
}

void inputData() {
    cin >> n >> m >> k;
    int a, b, c;
    for (int i=0; i<k; i++) {
        cin >> a;
        jewel[a] = true;
    }
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        bridge[a][b] = c;
        bridge[b][a] = c;
    }
}

/**
 * @return 방문X 섬 중, 가장 많은 보석을 견딜 수 있는 섬의 index로 갱신
 */
int getMaxRouteIndex() {
    int max = 0;
    int idx = 0;
    for (int i=1; i<=n; i++) {
        if (maxRoute[i] != 0 && visit[i] == false) {
            if (maxRoute[i] >= max) {
                max = maxRoute[i];
                idx = i;
            }
        }
    }
    return idx;
}

/**
 * 섬 방문 후, maxRoute 업데이트
 * @param node 방문하는 섬
 */
void updateRoute(int node) {
    visit[node] = true;
    int route = 0; // node를 통하는 경로
    for (int i=2; i<=n; i++) {
        if (bridge[node][i] != 0) {
            route = getMin(maxRoute[node], bridge[node][i]);
            maxRoute[i] = getMax(maxRoute[i], route);
        }
    }
}

/**
 * 다익스트라 알고리즘과 유사
 */
void setMaxRoute() {
    int currentNode = 1;
    maxRoute[1] = ISLAND_MAX;
    for (int i=2; i<=n; i++) {
        maxRoute[i] = bridge[1][i];
    }

    while(currentNode) {
        currentNode = getMaxRouteIndex();
        updateRoute(currentNode);
    }
}

void countJewel() {
    int count = 0;

    vector<int> jewelRoute;
    for (int i=1; i<ISLAND_MAX; i++) {
        if (jewel[i]) {
            jewelRoute.push_back(maxRoute[i]);
        }
    }
    sort(jewelRoute.begin(), jewelRoute.end());

    for (int j : jewelRoute) {
        if (count < j) {
            count++;
        }
    }

    cout << count;
}

int main() {
    inputData();
    setMaxRoute();
    countJewel();

    return 0;
}
