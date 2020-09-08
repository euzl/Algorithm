#include <iostream>
using namespace std;

int square(int n) {
    int d[n+1];
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i<=n; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    return d[n];
}

int main() {
    int t;
    cin >> t;
    int a = 0;
    while(t>0) {
        cin >> a;
        cout << square(a) << endl;
        t--;
    }
    return 0;
}
