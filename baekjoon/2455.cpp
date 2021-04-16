#include <cstdio>
using namespace std;

int main() {
    int in[4], out[4];

    int cur = 0;
    int max = -1;
    for (int i=0; i<4; i++) {
        scanf("%d %d", &out[i], &in[i]);
        cur = cur + in[i] - out[i];
        if (cur > max) max = cur;
    }
    printf("%d", max);
    return 0;
}
