#include <stdio.h>
using namespace std;
#define MAX_SIZE 10000
int main() {
    int deck[MAX_SIZE] = {0, };
    int start = 0, end = 0;
    int n;
    scanf("%d", &n);
    char input[11];
    int x;
    while(n--) {
        scanf("%s", &input);
        if (input[0] == 'p') {
            if (input[1] == 'u') {
                if (input[5] == 'f') {
                    scanf("%d", &x);
                    start = (MAX_SIZE + start - 1)%MAX_SIZE;
                    deck[start] = x;
                } else {
                    scanf("%d", &x);
                    deck[end] = x;
                    end = (end + 1)%MAX_SIZE;
                }
            } else {
                if (start == end) printf("-1\n");
                else if (input[4] == 'f') {
                    printf("%d\n", deck[start++]);
                    start %= MAX_SIZE;
                }
                else {
                    end = (end - 1 + MAX_SIZE)%MAX_SIZE;
                    printf("%d\n", deck[end]);
                }
            }
        } else if (input[0] == 's') {
            if (end >= start) printf("%d\n", end - start);
            else printf("%d\n", MAX_SIZE-start+end);
        } else if (input[0] == 'e') {
            if (end == start) printf("1\n");
            else printf("0\n");
        } else if (input[0] == 'f') {
            if (end == start) printf("-1\n");
            else printf("%d\n", deck[start]);
        } else if (input[0] == 'b') {
            if (end == start) printf("-1\n");
            else printf("%d\n", deck[(end - 1 + MAX_SIZE)%MAX_SIZE]);
        }
    }
    return 0;
}
