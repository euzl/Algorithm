#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string rot13 = "";
    for (char i : s) {
        if (i >= 'A') {
            if (i < 'A' + 13) {
                rot13 += i+13;
            } else if (i < 'a') {
                rot13 += 64 + 13 - 'Z' + i;
            } else if (i < 'a' + 13) {
                rot13 += i + 13;
            } else {
                rot13 += 64 + 13 - 'Z' + i;
            }
        } else {
            rot13 += i;
        }
    }
    cout << rot13;
    return 0;
}
