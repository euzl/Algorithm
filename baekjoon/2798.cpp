// 2798::블랙잭
#include <cstdio>

int main()
{
	int n, m, sum = 0, near = -1, num[100];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = num[i] + num[j] + num[k];
				if (sum > m)
					continue;
				else
					if (sum > near)
						near = sum;
			}
		}
	}
	printf("%d", near);
	return 0;
}
