// 1011::Fly me to the Alpha Centauri
#include <cstdio>

int main() {
	int t, x, y, l;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		l = y - x;
		for (int i = 1; i <= l; i++) {
			if ((l <= i * i) && (l > i * i - i)) {
				printf("%d\n", 2 * i - 1);
				break;
			}
			else if ((l > i * i) && (l <= i * i + i)) {
				printf("%d\n", 2 * i);
				break;
			}
		}
	}
	return 0;
}
