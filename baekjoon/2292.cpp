// 2292::벌집
#include <cstdio>

int main() {
	int n, i = 0;
	scanf("%d", &n);
	for (i; (3 * i * (i + 1) + 1) < n; i++);
	printf("%d", i + 1);
	return 0;
}
