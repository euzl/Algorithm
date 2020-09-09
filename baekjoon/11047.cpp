#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, k, cnt=0;
    scanf("%d %d", &n, &k);
    int value[10];
    for (int i=0; i<n; i++) {
        scanf("%d", &value[i]);
    }
    int s = n-1;
    while(k>0) {
        for (int i = s; i >=0; i--) {
            if (value[i] <= k) {
                k -= value[i];
                ++cnt;
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
