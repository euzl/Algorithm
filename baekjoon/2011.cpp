#include <cstdio>
#include <string>
using namespace std;

int main() {
    char tmp[5001];
    scanf("%s", tmp);
    string n = tmp;

    if (n[0] == '0') {
        printf("%d", 0);
        return 0;
    }

    int dp[3] = {1, 1, 0};
    int i=2;
    int num = n[n.size()-1] - '0';

    // 여러 해석의 여지가 있는 경우
    // 0: 1,2, 1: 3~6, 2: 7~9, 3: 0
    int flag = num <=2 ? 0 : num <= 6 ? 1 : 2;
    if (num%10 == 0) {
        flag = 3;
//        i++;
    }
    for (int k = n.size()-2; k>=0; k--) {
        if (flag == 3) { // 이전 숫자가 0일 때
            if ((n[k] - '0' == 1) || (n[k] - '0' == 2)) {
                flag = 3;
            } else {
                // 0 으로 해줌
                break;
            }
        } else { // 1~9
            if (n[k] - '0' == 1) {
                if (flag == 0) {
                    dp[i%3] = (dp[(i-1)%3] + dp[(i-2)%3])%1000000;
                } else {
                    dp[i%3] = (dp[(i-1)%3]*2)%1000000;
                }
                i++;
                flag = 0;
            } else if (n[k] - '0' == 2) {
                if (flag == 0) {
                    dp[i%3] = (dp[(i-1)%3] + dp[(i-2)%3])%1000000;
                    i++;
                } else if (flag == 1) {
                    dp[i%3] = (dp[(i-1)%3]*2)%1000000;
                    i++;
                }
                flag = 0;
            } else if (n[k] - '0' == 0) {
                flag = 3;
            } else if (n[k] - '0' <=6) {
                flag = 1;
            } else {
                flag = 2;
            }
        }
    }

    printf("%d", dp[(i-1)%3]%1000000);

    return 0;
}
