#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string ps;
    int cnt=0;
    bool isRight;
    while(n--) {
        cin >> ps;

        cnt = 0;
        isRight = true;

        for (int i=0; i<ps.size(); i++) {
            if (ps[i] == '(') cnt++;
            else cnt--;

            if (cnt < 0) {
                isRight = false;
                break;
            }
        }

        if (isRight && cnt == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
