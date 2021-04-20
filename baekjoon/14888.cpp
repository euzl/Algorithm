#include <cstdio>
#include <string.h>
using namespace std;
int N=0;
#define MAX_SIZE 11
#define INF 1000000000
int num[MAX_SIZE];
int mins = INF;
int maxs = -INF;

void DFS(int idx, int pre, int oper[]) {
    if (idx == N) {
        if (pre < mins || mins == INF) mins = pre;
        if (pre > maxs || maxs == -INF) maxs = pre;
        return;
    }
    int nO[4] = {0, };
    memcpy(nO, oper, sizeof(nO)); // copy
    int sum;

    if (nO[0]) {
        sum = pre+num[idx];
        --nO[0];
        DFS(idx+1, sum, nO);
        ++nO[0];
    }

    if (nO[1]) {
        sum = pre-num[idx];
        --nO[1];
        DFS(idx+1, sum, nO);
        ++nO[1];
    }

    if (nO[2]) {
        sum = pre*num[idx];
        --nO[2];
        DFS(idx+1, sum, nO);
        ++nO[2];
    }

    if (nO[3]) {
        if (pre*num[idx] < 0) {
            pre *= -1;
            sum = pre/num[idx];
            sum *= -1;
        } else {
            sum = pre/num[idx];
        }
        --nO[3];
        DFS(idx+1, sum, nO);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &num[i]);
    int oper[4];
    for (int i=0; i<4; i++) scanf("%d", &oper[i]);

    DFS(1, num[0], oper);
    printf("%d\n%d", maxs, mins);
    return 0;
}
