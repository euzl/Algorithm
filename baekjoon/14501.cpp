#include <cstdio>
using namespace std;
#define MAX_SIZE 17
int T[MAX_SIZE];
int P[MAX_SIZE];
int Pre[MAX_SIZE];
int getMax(int a, int b) { return a>b ? a : b;}
int main() {
    int N;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    int done;
    for (int i=1; i<=N; i++) {
        Pre[i] = getMax(Pre[i], Pre[i-1]);
        done = i+T[i];
        if (done > N+1) continue;
        Pre[done] = getMax(Pre[done], Pre[i] + P[i]);
    }

    int ans=0;
    for (int i=2; i<=N+1; i++) {
        if (Pre[i] > ans) ans = Pre[i];
    }
    printf("%d", ans);
    return 0;
}
