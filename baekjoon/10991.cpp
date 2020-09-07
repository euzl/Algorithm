#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=1; j<=t; j++) {
        for (int k=t-j; k>0; k--) {
            cout<<' ';
        }
        for (int k=0; k<j; k++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
