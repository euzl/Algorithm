#include <iostream>
using namespace std;

int getMax(int a, int b) {
    return a>b? a : b;
}

int main() {
    int t = 0;
    scanf("%d", &t);

    int arr[1001];
    int cnt[1001] = {0, };
    int max = -1;

    for (int i=0; i<t; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<t; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j] < arr[i]) {
                if (cnt[j] > cnt[i]) {
                    cnt[i] = cnt[j];
                }
            }
        }
        cnt[i] += arr[i];
        max = getMax(max, cnt[i]);
    }

    cout << max;

    return 0;
}
