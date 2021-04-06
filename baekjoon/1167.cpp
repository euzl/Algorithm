#include <cstdio>
#include <vector>
using namespace std;
#define TREE_MAX 100001

int V=0;
vector<pair<int, int>> trees[TREE_MAX];
int diameter = -1;
int far = 0;

void findDiameter(int prev, int cur, int sum) {
    if (sum > diameter) {
        far = cur;
        diameter = sum;
    }
//    printf("prev:%4d | cur:%4d | sum:%4d\n", prev, cur, sum);
    for (pair<int, int> t : trees[cur]) {
        if (t.first == prev) continue;
        findDiameter(cur, t.first, sum + t.second);
    }
}

int main() {
    scanf("%d", &V);
    int node, a, b;
    for (int i=1; i<=V; i++) {
        scanf("%d", &node);
        while (1) {
            scanf("%d", &a);
            if (a== -1) break;
            scanf("%d", &b);
            trees[node].push_back({a, b});
        }
    }
    findDiameter(0, 1, 0);
    findDiameter(0, far, 0);

    printf("%d", diameter);
}
