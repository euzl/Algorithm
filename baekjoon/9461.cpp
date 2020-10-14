#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);

    long long p[101] = {0, 1, 1, 1, 2, };
    while(t--) {
        scanf("%d", &n);
        for (int i=5; i<=n; i++) {
            if (p[i] != 0) continue;
            p[i] = p[i-1] + p[i-5];
        }
        cout<<p[n]<<endl;
    }
    return 0;
}
