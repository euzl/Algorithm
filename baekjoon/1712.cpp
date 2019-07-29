//1712::손익분기점
#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int i = a / (c - b) + 1;

	if (i > 0)
		printf("%d", i);
	else
		printf("-1");
	return 0;
}
