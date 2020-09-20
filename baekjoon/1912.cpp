#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int input;

    vector<int> arr;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &input);
        arr.push_back(input);
    }

    int curMax = arr[0]; // 최대값 저장
    for (int i=1; i<n; i++) {
        if (arr[i-1] > 0) {
            arr[i] += arr[i-1];
        }
        if (curMax < arr[i]) {
            curMax = arr[i]; // 최대값 갱신
        }
    }

    printf("%d", curMax);

    return 0;
}
