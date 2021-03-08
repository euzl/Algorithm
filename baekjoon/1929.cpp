#include <cstdio>
using namespace std;
bool sosu(int a) {
    if (a == 1) return false;
    for (int i=2; i*i <= a; i++) {
        if (a%i == 0) return false;
    }
    return true;
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    while (m<=n) {
        if (sosu(m)) printf("%d\n", m);
        ++m;
    }
    return 0;
}
