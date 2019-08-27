//2753::윤년
#include <cstdio>

int main() {
	int year, yoon;
	scanf("%d", &year);

	year % 4 != 0 ? yoon = 0 : year % 400 == 0 ? yoon = 1 : year % 100 != 0 ? yoon = 1 : yoon = 0;
	printf("%d", yoon);

	return 0;
}
