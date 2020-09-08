#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    int inf = 1000000;

    int toOne[1000000] = {-1, 0, 1, 1};
    int three;
    int two;
    int one;

    for (int i=4; i<=t; i++) {
        if (i%3==0) {
            three = toOne[i/3] + 1;
        } else {
            three = inf;
        }
        if (i%2==0) {
            two = toOne[i/2] + 1;
        } else {
            two = inf;
        }
        one = toOne[i-1] + 1;

        toOne[i] = min({three, two, one});
    }

    cout << toOne[t] <<endl;

    return 0;
}
