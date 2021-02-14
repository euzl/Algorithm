#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<string> list;
    list.push_back(s[s.length()-1]+"");

    for (int i=s.length()-1; i>=0; i--) {
        list.push_back(s[i] + list.back());
    }

    sort(list.begin(), list.end());

    for (int i=1; i<list.size(); i++) {
        cout << list[i] << endl;
    }

    return 0;
}
