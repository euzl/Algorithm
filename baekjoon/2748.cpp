// 2748::피보나치수 2
#include <cstdio>

int main() {
	int n;
	long long int fib[91]; // int로 하니까 범위가 부족 ㅠㅠ 
	fib[0] = 0, fib[1] = 1;
	scanf("%d", &n);
	if (n >= 2) {
		for (int i = 2; i < n + 1; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
	}
	printf("%lld", fib[n]);

	return 0;
}
