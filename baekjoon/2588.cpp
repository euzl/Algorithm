// 2588::곱셈
#include <cstdio>

int main()
{
	int a1, a2, a3, a4, a5, a6;
	scanf("%d%d", &a1, &a2);
	a3 = a1 * (a2 % 10);
	a4 = a1 * (a2 / 10 % 10);
	a5 = a1 * (a2 / 100);
	a6 = a3 + a4 * 10 + a5 * 100;
	printf("%d\n%d\n%d\n%d", a3, a4, a5, a6);
	return 0;
}
