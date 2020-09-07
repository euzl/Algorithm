#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = t-1; k >= 1-t; k--) {
        for (int j=0; j<abs(k); j++) {
            cout << ' ';
        }
        for (int i=0; i<t-abs(k); i++) {
            cout << '*';
        }
        if (k > 1-t) cout << endl;
    }
    return 0;
}
