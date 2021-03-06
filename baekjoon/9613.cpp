#include <cstdio>
#include <string>
using namespace std;
int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int t;
    scanf("%d", &t);
    int n;
    while(t--) {
        scanf("%d", &n);
        long long gcdSum = 0;
        int arr[100];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]); // input
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdSum += gcd(arr[i], arr[j]);
            }
        }
        printf("%lld\n", gcdSum);
    }
    return 0;
}
