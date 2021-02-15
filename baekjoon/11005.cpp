#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, b;
    cin >> n >> b;
    int mod;
    string result="";
    while(n>0) {
        mod = n%b;
        n /= b;
        if (mod < 10) {
            result = to_string(mod) + result;
        } else {
            result = char(55 + mod) + result;
        }
    }
    cout << result;

    return 0;
}
