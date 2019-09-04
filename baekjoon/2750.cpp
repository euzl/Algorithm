// 2750::수 정렬하기
#include <cstdio>

int main() {
	int num[1000] = { 0, };
	int t, i=0, tmp;
	scanf("%d", &t);
	for(i=0;i<t;i++) scanf("%d", num + i);

	for (i = 0; i < t; i++) {
		for (int j = 0; j < t-1; j++) {
			if (num[j] > num[j + 1]) {
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < t; i++)
		printf("%d\n", num[i]);
	return 0;
}
