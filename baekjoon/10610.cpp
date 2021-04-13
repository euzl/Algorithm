#include <cstdio>
using namespace std;
int num[10];
int main() {
    int N;
    int sum = 0;
    while(scanf("%1d", &N) != EOF) {
        sum += N;
        ++num[N];
    }

    if (num[0] == 0 || sum%3 != 0) {
        printf("-1");
        return 0;
    }

    for (int i=9; i>=0; i--) {
        for (int j=0; j<num[i]; j++) {
            printf("%d", i);
        }
    }
    
    return 0;
}
