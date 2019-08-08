// 10250::ACM호텔
// 틀렸는데 왜 틀렸는지 모르겠다... 
#include <cstdio>

int main()
{
	int t, h, w, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &h, &w, &n);
		printf("%d\n", (n % h) * 100 + n / h + 1);
	}

	return 0;
}
