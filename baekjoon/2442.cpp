#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        for (int j=0; j<t-i; j++) {
            cout << ' ';
        }
        for (int j=0; j<2*i-1; j++) {
            cout << '*';
        }
        if (i < t) cout<< endl;
    }
    return 0;
}
