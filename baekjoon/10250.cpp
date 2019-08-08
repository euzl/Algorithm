// 10250::ACM호텔
// n%h == 0 인 경우, 다르게 처리해줘야함!
#include <cstdio>

int main()
{
	int t, h, w, n, hosu;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &h, &w, &n);
		hosu = n % h != 0 ? (n % h) * 100 + n / h + 1 : h * 100 + n / h;
		printf("%d\n", hosu);
	}

	return 0;
}
