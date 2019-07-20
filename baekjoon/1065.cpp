//1065::한 수
#include <cstdio>

int main() {
	int n, cnt;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	else
		cnt = 99;

	for (int i = 100; i <= n; i++) {
		if (i == 1000)
			break;
		if ((i % 10 - i % 100 / 10) == (i % 100 / 10 - i % 1000 / 100))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
