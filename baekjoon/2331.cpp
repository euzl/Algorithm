// 2331::부분합
#include <cstdio>

void inersum(int num, int& sum) {
	sum += num % 10;
	num = num / 10;
	if (num == 0) return;
	else inersum(num, sum);
}

int main() {
	int n, sum;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		sum = i;
		inersum(i, sum);
		if (n == sum) {
			printf("%d", i);
			return 0;
		}
		if (n == i)
			printf("%d", 0);
	}
	return 0;
}
