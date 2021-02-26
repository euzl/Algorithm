#include <cstdio>

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int main() {
    int t;
    scanf("%d", &t);
    int a, b;
    while(t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a, b));
    }

    return 0;
}
