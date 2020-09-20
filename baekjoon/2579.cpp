#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int input;

    vector<int> arr[3];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &input);
        arr[0].push_back(0);
        arr[1].push_back(input);
        arr[2].push_back(0);
    }

    for (int i=n-2; i>=0; i--) {
        arr[0][i] = max(arr[1][i+1], arr[2][i+1]); // 이번값 포함 X
        arr[2][i] = arr[1][i+1] + arr[1][i]; // 총 2개 합
        arr[1][i] = arr[0][i+1] + arr[1][i]; // 총 1개 합
        if (i == n-2) arr[1][i] = 0;
    }

    printf("%d", max({arr[0][0], arr[1][0], arr[2][0]}));

    return 0;
}
