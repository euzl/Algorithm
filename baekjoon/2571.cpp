#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> num;
    int t;
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    printf("%d\n", num[0]);
    for (int i=1; i<n; i++) {
        if (num[i] != num[i-1]) {
            printf("%d\n", num[i]);
        }
    }
    return 0;
}
