#include <cstdio>
using namespace std;

int main() {

    char stick[100001];
    scanf("%s", &stick);

    int rest = 0;
    int sum = 0;

    for (int i=0; stick[i]; i++) {
        if (stick[i] == '(') {
            if (stick[i+1] == ')') {
                // 레이저 타임
                sum += rest;
                ++i; // 한 차례 패스
            } else {
                ++rest; // 막대기 추가
            }
        } else {
            --rest; // 막대기 제거
            ++sum; // 짜투리 막대기 추가
        }
    }

    printf("%d", sum);

    return 0;
}
