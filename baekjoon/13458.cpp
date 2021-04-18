#include <cstdio>
using namespace std;
int A[1000000];
int main() {
    int N, B, C;
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    long long sum = 0;
    for (int i=0; i<N; i++) {
        A[i] -= B;
        ++sum;
        if (A[i] <= 0) continue;
        sum += A[i]/C;
        if (A[i]%C) ++sum;
    }
    printf("%lld", sum);
    return 0;
}
