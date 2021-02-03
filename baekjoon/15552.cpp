#include <iostream>
using namespace std;


int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int a, b;
    while(t--) {
        cin >> a >> b;
        cout << a+b << '\n';
    }

    return 0;
}
