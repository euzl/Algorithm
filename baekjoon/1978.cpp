#include <cstdio>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    int i, j;
    int cnt = 0;
    int isSosu;
    while(n--) {
        scanf("%d", &num);
        i = 2;
        j = num;
        isSosu = true;
        while (i < j) {
            if (num%i == 0) {
                isSosu = false;
                break;
            }
            j = num/i;
            ++i;
        }
        if (isSosu && num >= 2) ++cnt;
    }
    printf("%d", cnt);
    return 0;
}
