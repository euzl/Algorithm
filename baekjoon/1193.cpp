// 1193::분수찾기
#include <cstdio>

int main() {
	int x, i = 0;
	scanf("%d", &x);
	while (x > i * (i + 1) / 2) { // 몇 번째 i에 속하는지 찾기
		i++;
	} 
	//printf("# x : %d | i : %d\n", x, i);
	for (int j = 0; j < i; j++) { // i안에서 몇 번째인지 찾기
		if (i * (i + 1) / 2 - j == x) { // x를 찾으면?
			i % 2 != 0 ? printf("%d/%d\n", 1 + j, i - j) : printf("%d/%d\n", i - j, 1 + j);
			break;
		}
	}
	return 0;
}
