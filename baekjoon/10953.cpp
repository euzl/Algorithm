#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t > 0) {
        string testcase;
        cin >> testcase;
        cout<< testcase[0] + testcase[2] - 96  << endl;
        t--;
    }
    return 0;
}
