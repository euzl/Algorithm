#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    int a[2000000];
    scanf("%d %d", &n, &m);

    int sum = 0;
    for (int i = 0; i < n+m; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a+n+m);

    for (int i=0; i<n+m; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
