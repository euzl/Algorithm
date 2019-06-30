// 1110::더하기 사이클
// 계속 틀렸었는데, while(n != newn)을 while(1)과 if(n==newn) break; 로 바꾸니까 해결됐다. 왜지???

#include <stdio.h>
int main() {
	int n, newn = 0, sumnum = 0, cnt = 0; scanf("%d", &n);
	while (1) {
		if (cnt == 0) newn = n;
		sumnum = newn / 10 + newn % 10;
		newn = (newn % 10) * 10 + sumnum % 10;
		cnt++;
		if (n == newn)
			break;
	}
	printf("%d", cnt);
}
