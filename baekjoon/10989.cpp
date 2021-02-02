#include <cstdio>
using namespace std;

#define MAX_NUM 10002

int arr[MAX_NUM] = {0, };

int main(void)
{
    int size;
    scanf("%d", &size);

    int i;
    int max = -1;
    int input;

    // 카운트
    for (i=0; i<size; i++) {
        scanf("%d", &input);
        ++arr[input];
        if (input > max) max = input;
    }

    // 출력
    int j=0;
    for (i=1; i<=max; i++) {
        for (j=0; j<arr[i]; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}
