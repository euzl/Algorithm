#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = t - 1; k >= -t+1; k--) {
        for (int i=1; i<t-abs(k); i++) {
            cout << ' ';
        }
        for (int j=0; j<= 2*abs(k); j++) {
            cout << '*';
        }
        if (k > 1-t) cout << endl;
    }
    return 0;
}
