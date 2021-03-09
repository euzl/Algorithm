#include <cstdio>
using namespace std;
#define MAX 1000000
int sosu[MAX];

bool isSosu(int a) {
    if (a == 1) return false;
    for (int i=2; i*i <= a; i++) {
        if (a%i == 0) return false;
    }
    return true;
}

void findSosu() { // 백만이하의 홀수인 소수 찾기
    int m = 3;
    while (m<=MAX) {
        if (isSosu(m)) sosu[m] = 1;
        m += 2;
    }
}

int getB(int num) {
    for (int i=num; i>2; i -= 2) {
        if (sosu[i] == 1) return i;
    }
    return 0;
}

int getA(int num) {
    for (int i=num; i<MAX; i += 2) {
        if (sosu[i] == 1) return i;
    }
    return 0;
}

int main() {
    findSosu();
    int n, a, b;
    bool isTrue;
    while(1) {
        isTrue = false;
        scanf("%d", &n);
        if (n == 0) return 0;

        a = 3, b = getB(n-1);
        while ( b*2 >= n) {
            if (a+b == n) {
                isTrue = true;
                break;
            } else if (a+b > n) {
                a = 3;
                b = getB(b-2);
            } else {
                if (a == b) {
                    a= 3;
                    b = getB(b-2);
                } else {
                    a = getA(a+2);
                }
            }
        }
        if (isTrue) {
            printf("%d = %d + %d\n", n, a, b);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}
