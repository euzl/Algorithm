#include <iostream>
using namespace std;

int getMax(int a, int b) {
    return a>b? a : b;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int arr[1001];
    int length[2][1001] = {0, };
    int max = -1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);


    // 오름차순
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] != arr[j]) {
                if (arr[i] > arr[j]) {
                    length[0][i] = getMax(length[0][i], length[0][j]);
                }
            }
        }
        length[0][i]++;
    }
    // 내림차순
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>i; j--) {
            if (arr[i] != arr[j]) {
                if (arr[i] > arr[j]) {
                    length[1][i] = getMax(length[1][i], length[1][j]);
                }
            }
        }
        length[1][i]++;

        if (length[0][i] + length[1][i] - 1 > max) {
            max = length[0][i] + length[1][i] - 1;
        }
    }

    cout << max;

    return 0;
}
