#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[11];
    int verdict = 0;
    int input;
    for(int i=0; i<11; i++) {
        scanf("%d %d", &arr[i], &input);
        verdict += 20*input;
    }

    sort(arr, arr+11);

    int penalty = arr[0];
    for (int i=1; i<11; i++) {
        arr[i] += arr[i-1];
        penalty += arr[i];
    }

    printf("%d", penalty + verdict);

    return 0;
}
