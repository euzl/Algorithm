//2775::부녀회장이 될테야
#include <cstdio>

int main()
{
	int apart[15][14];
	int i, j, k, n, t;
	scanf("%d", &t);

	//초기화
	for (i = 0; i < 14; i++) apart[0][i] = i + 1; //0층
	for (j = 0; j < 15; j++) apart[j][0] = 1; //매 1호

	while (t--) {
		scanf("%d%d", &k, &n);
		for (i = 1; i <= k; i++)
			for (j = 1; j < n; j++)
				apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		printf("%d\n", apart[k][n - 1]);
	}
	return 0;
}
