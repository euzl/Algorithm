#include <cstdio>
#include <cmath>
using namespace std;
#define MAX_D 1000000 // 9999 -> 26244 -> 9888 인데 범위초과생겨서 그냥 엄청 올려버림
int isVisit[MAX_D]; // 방문한애 index 저장
int getCurrentNum(int prev, int p) {
    int num = 0;
    while (prev) {
        num += pow(prev%10, p);
        prev /= 10;
    }
    return num;
}
int main() {
    int a, p;
    scanf("%d %d", &a, &p);
    int now = 1;
    int number = a;
    isVisit[a] = now;
    while(1) {
        ++now;
        number = getCurrentNum(number, p);
        if (isVisit[number]) {
            break;
        } else {
            isVisit[number] = now;
        }
    }
    printf("%d", isVisit[number] - 1);
    return 0;
}
