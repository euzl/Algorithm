// 7568::덩치
#include <cstdio>

int main()
{
	int n, x[50], y[50], rank[50] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if ((x[i] < x[j]) && (y[i] < y[j]))
				rank[i]++;
			else if ((x[i] > x[j]) && (y[i] > y[j]))
				rank[j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", rank[i] + 1);
	}
	return 0;
}
