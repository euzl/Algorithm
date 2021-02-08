#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int *arr = new int[n];

    int ptr = 0;
    string cmd;
    while(n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> arr[ptr];
            ++ptr;
        } else if (cmd == "size") {
            cout << ptr << '\n';
        } else if (cmd == "empty") {
            if (ptr == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            if (ptr == 0) {
                cout << "-1\n";
                continue;
            }
            cout << arr[ptr-1] << '\n';
            if (cmd == "pop") {
                --ptr;
            }
        }
    }

    delete arr;

    return 0;
}
