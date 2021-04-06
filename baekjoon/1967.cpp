#include <cstdio>
#include <vector>
using namespace std;
#define TREE_MAX 10001

int n=0;
vector<pair<int, int>> trees[TREE_MAX];
int diameter = -1;
int far = 0;

void findDiameter(int prev, int cur, int sum) {
    if (sum > diameter) {
        far = cur;
        diameter = sum;
    }
    for (pair<int, int> t : trees[cur]) {
        if (t.first == prev) continue;
        findDiameter(cur, t.first, sum + t.second);
    }
}

int main() {
    scanf("%d", &n);
    int p,c,w;
    for (int i=1; i<n; i++) {
        scanf("%d", &p);
        scanf("%d", &c);
        scanf("%d", &w);
        trees[p].push_back({c, w});
        trees[c].push_back({p, w});
    }
    findDiameter(0, 1, 0);
    findDiameter(0, far, 0);

    printf("%d", diameter);
}
