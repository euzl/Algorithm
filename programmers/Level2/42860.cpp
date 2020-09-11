// "BBBAAAB" 9
// "ABABAAAAABA" 11

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int leftnright(int a, int b) {
    if (a > 0) a--;
    b--;
    if (a < b) return a*2 + b;
    else return a + b*2;
}

int solution(string name) {
    int answer = 0;

    // 좌우조작
    int a, b; // A묶음의 시작과 끝 idx 저장
    int maxA, maxB; // 가장 긴 A의 시작과 끝 idx 저장
    int maxLength = 0;
    bool isSeries = false; // 이전값도 A였는지
    bool isFind = false;
    for (int i=0; i<name.length(); i++) {
        if (name[i] == 'A') {
            // index 갱신
            if (!isSeries) {
                a = i;
                b = i;
                isSeries = true;
                isFind = true;
            }
            else {
                b = i;
            }
            // 최고길이 갱신
            if (b - a >= maxLength) {
                maxLength = b - a;
                maxA = a;
                maxB = b;
            }
        } else {
            isSeries = false;
        }
    }
    if (isFind) {
        answer = leftnright(maxA, name.length() - maxB);
    } else {
        answer = name.length() - 1;
    }

    cout<<answer<<endl;

    // 상하조작
    for (char n : name) {
        if (n <= 'N') answer += n-'A';
        else answer += 'Z'-n+1;
    }
    return answer;
}
