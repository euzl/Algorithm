// 2292::벌집
#include <cstdio>

int main() {
	int n, i = 0;
	scanf_s("%d", &n);
	while (1) {
		if ((3 * i * (i + 1) + 1) >= n) {
			printf("%d", i + 1);
			break;
		}
		i++;
	}
	return 0;
}
