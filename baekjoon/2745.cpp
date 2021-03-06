#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string n;
    int b;
    cin >> n >> b;
    int result = 0;
    int size = n.length();
    for (int i=0; i<size; i++) {
        if (n[i] >= 'A') {
            n[i] = n[i] - 'A' + 10;
        } else {
            n[i] = n[i] - '0';
        }
        result += n[i]*pow(b, size-i-1);
    }
    cout << result;
    return 0;
}
