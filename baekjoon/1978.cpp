#include <cstdio>

int main()
{
	int t, ot, i, num, cnt = 0;
	scanf("%d", &t);
	ot = t;
	while (t--) {
		scanf("%d", &num);
		for (i = 2; i < num / 2; i++) {
			if (num % i == 0)
				cnt++;

		}
	}
	printf("%d", ot - cnt);
	return 0;
}
