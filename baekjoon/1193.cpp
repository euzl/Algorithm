// 1193::분수찾기 (실패)
#include <cstdio>

int main() {
	int x, i = 0;
	scanf("%d", &x);
	while (x < i * (i + 1) / 2) {
		i++;
	}
	for (int j = 0; j < i; j++) {
		if (i - j == x) {
			printf("%d/%d", 1 + j, i - j);
			break;
		}
	}
	return 0;
}
