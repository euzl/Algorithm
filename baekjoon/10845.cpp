#include <stdio.h>
using namespace std;
#define MAX_SIZE 10000
int main() {
    int queue[MAX_SIZE] = {0, };
    int start = 0, end = 0;
    int n;
    scanf("%d", &n);
    char input[6];
    int x;
    while(n--) {
        scanf("%s", &input);
        if (input[0] == 'p') {
            if (input[1] == 'u') {
                scanf("%d", &x);
                queue[(end++)%MAX_SIZE] = x;
            } else {
                if (start == end) printf("-1\n");
                else printf("%d\n", queue[(start++)%MAX_SIZE]);
            }
        } else if (input[0] == 's') {
            if (end >= start) printf("%d\n", end - start);
            else printf("%d\n", MAX_SIZE-start+end);
        } else if (input[0] == 'e') {
            if (end == start) printf("1\n");
            else printf("0\n");
        } else if (input[0] == 'f') {
            if (end == start) printf("-1\n");
            else printf("%d\n", queue[start]);
        } else if (input[0] == 'b') {
            if (end == start) printf("-1\n");
            else printf("%d\n", queue[end-1]);
        }
    }
    return 0;
}
