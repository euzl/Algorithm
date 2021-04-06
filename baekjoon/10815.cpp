#include <cstdio>
#include <algorithm>
using namespace std;

#define CARD_MAX 500001
int card[CARD_MAX];
int find_card[CARD_MAX];

int main() {
    int N, M;
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &card[i]);
    scanf("%d", &M);
    for (int i=0; i<M; i++) scanf("%d", &find_card[i]);

    sort(card, card+N);

    int cur, left, right;
    for (int m=0; m<M; m++) {
        left = 0;
        right = N;
        bool isExist = false;

        while (left <= right) {
            cur = (left + right)/2;
            if (card[cur] == find_card[m]) {
                isExist = true;
                break;
            } else if (card[cur] > find_card[m]) {
                right = cur - 1;
            } else {
                left = cur + 1;
            }
        }
        printf(isExist ? "1 " : "0 ");
    }

    return 0;
}
