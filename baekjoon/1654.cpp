#include <cstdio>
using namespace std;
long long ransun[10000];
int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    long long min = 1;
    long long max = 1;
    for (int i=0; i<K; i++) {
        scanf("%lld", &ransun[i]);
        if (ransun[i] > max) max = ransun[i];
    }
    unsigned long long size;
    unsigned long long maxSize = 0;
    long long count;
    while(max-min >= 0) {
        size = (min+max)/2;
        count = 0; // init
        for (int i=0; i<K; i++) {
            count += ransun[i]/size;
        }
        if (count < N) {
            max = size-1;
        } else if (count >= N) {
            if (size > maxSize) maxSize = size;
            min = size+1;
        }
    }
    printf("%lld", maxSize);
    return 0;
}
