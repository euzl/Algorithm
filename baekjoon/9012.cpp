#include <cstdio>
using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    char ps[51];
    int cnt;
    while(n--) {
        scanf("%s", &ps);
        cnt = 0;
        for (int i=0; ps[i] && cnt >= 0; i++) {
            ps[i] == '(' ? cnt++ : cnt--;
        }
        puts(cnt ? "NO" : "YES");
    }

    return 0;
}
