#include <cstdio>
using namespace std;

int main() {
    int E,S,M;
    scanf("%d %d %d", &E, &S, &M);
    int y = 0;
    E--;
    S--;
    M--;
    while(1) {
        if (y%15 == E && y%28 == S && y%19 == M) break;
        ++y;
    }
    ++y;
    printf("%d", y);
    return 0;
}
