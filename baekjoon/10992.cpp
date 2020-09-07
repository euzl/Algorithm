#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=1; i<t; i++) {
        cout<< ' ';
    }
    cout<< '*' << endl;
    if (t==1) return 0;

    for (int i=2; i<t; i++) {
        for (int j=t-i; j>0; j--) {
            cout<< ' ';
        }
        cout<< '*';
        for (int j=2*(i-1)-1; j>0; j--) {
            cout<< ' ';
        }
        cout << '*' <<endl;
    }

    for (int i=0; i<2*t-1; i++) {
        cout<< '*';
    }

    return 0;
}
