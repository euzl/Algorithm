#include <cstdio>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[5001] = {0, };

    int i = k-1;
    int cnt = 0;
    int jump = k;

    printf("<");
    while (cnt < n) {
        if (arr[i] == 0) {
            if (jump >= k-1) {
                if (cnt < n-1) printf("%d, ", i+1);
                else printf("%d>", i+1);
                cnt++;
                arr[i] = 1;
                jump = 0; // init
            } else {
                ++jump;
                i = (i+1)%n;
            }
        } else {
            i = (i+1)%n;
        }
    }

    return 0;
}
