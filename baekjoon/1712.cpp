//1712::손익분기점
#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	if (c <= b)
		printf("-1");
	else
		printf("%d", a / (c - b) + 1);
	return 0;
}
