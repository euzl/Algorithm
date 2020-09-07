
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cout<<"Case #" << i << ": "<< a <<" + " << b << " = " << a+b <<endl;
    }
    return 0;
}
