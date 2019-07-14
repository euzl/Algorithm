// 3052::나머지
#include <cstdio>
int main()
{
	int input_num[10];
	bool check[42] = { false, };
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input_num[i]);
		check[input_num[i] % 42] = true;
	}
	for (int i = 0; i < 42; i++)
		if (check[i])
			cnt++;
	printf("%d", cnt);
}
