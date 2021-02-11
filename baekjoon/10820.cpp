#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n=100;
    bool isEnd = false;
    while(n--) {

        fflush(stdin);
        getline(cin, s);
        if (s.length() == 0) break;
        int r[4] = {0,}; // 소문자 대문자 숫자 공백
        for (int i = 0; s[i]; i++) {
            if (s[i] == ' ') ++r[3];
            else if (s[i] >= 48 && s[i] <= 57) ++r[2]; // 숫자
            else if (s[i] >= 65 && s[i] <= 90) ++r[1]; // 대문자
            else if (s[i] >= 97 && s[i] <= 122) ++r[0]; // 소문자
        }

        printf("%d %d %d %d\n", r[0], r[1], r[2], r[3]);

        if(isEnd) break;
    }
    return 0;
}
