#include <cstdio>
using namespace std;
int tree[1000000];
int main() {
    int N;
    long long M;
    long long low = 0, high = 0;
    scanf("%d %lld", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &tree[i]);
        if (tree[i] > high) high = tree[i];
    }
    long long maxH = 0;
    long long sum;
    long long temp;
    while(high >= low) {
        sum = 0;
        int h = (low + high) / 2;
        for (int i = 0; i < N; i++) {
            temp = tree[i] - h;
            if (temp > 0) sum += temp;
        }
        if (sum >= M) {
            if (h > maxH) maxH = h;
            low = h+1;
        } else {
            high = h-1;
        }
    }
    printf("%lld", maxH);
    return 0;
}
