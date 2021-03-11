#include <cstdio>
using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int team = 0;
    while (N && M) {
        N -= 2;
        M -= 1;
        if (N >=0 && M >= 0 && (N+M) >= K) ++team;
        else break;
    }
    printf("%d", team);
    return 0;
}
