// 2908::상수
#include <cstdio>

int main()
{
	int a, b, na, nb;
	scanf("%d%d", &a, &b);
	na = a % 10 * 100 + ((a / 10) % 10) * 10 + a / 100;
	nb = b % 10 * 100 + ((b / 10) % 10) * 10 + b / 100;
	printf("%d", na >= nb ? na : nb);

	return 0;
}
