#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    long long *deck = new long long[n];

    for (int i=0; i<n; i++) {
        cin >> deck[i];
    }
    sort(deck, deck + n);

    // deck[0] 을 처리하고 시작
    int countTemp = 1;
    int countMax = 1;
    long long mostNum = deck[0];

    // deck[1] 부터 ~
    for (int i=1; i<n; i++) {
        if (deck[i] == deck[i-1]) {
            ++countTemp;
            if (countTemp > countMax) {
                countMax = countTemp;
                mostNum = deck[i-1];
            }
        } else {
            countTemp = 1;
        }
    }

    cout << mostNum;

    delete deck;

    return 0;
}
