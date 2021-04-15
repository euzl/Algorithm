#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int k=0; k<t; k++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int c, d;
        for (int i=0; i<m; i++) {
            scanf("%d %d", &c, &d);
        }
        printf("%d\n", n-1);
    }

    return 0;
}
