#include <cstdio>
#include <algorithm>
using namespace std;

#define CARD_MAX 20000001
#define ZERO 10000000
int card[CARD_MAX];
int N=0;


int main() {
    int M;
    scanf("%d", &N);
    int c;
    for (int i=0; i<N; i++) {
        scanf("%d", &c);
        ++card[ZERO+c];
    }
    scanf("%d", &M);
    int fc;
    for (int i=0; i<M; i++) {
        scanf("%d", &fc);
        printf("%d ", card[ZERO+fc]);
    }
    return 0;
}
