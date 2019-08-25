// 5622::다이얼
#include <iostream>
using namespace std;

int main()
{
	char num[15];
	int time = 0, n;
	int i = 0, cnt = 15;
	cin >> num;
	while (cnt--) {
		n = int(num[i]) - 65;
		if (n < 0 || n>25)
			break;
		if (n >= 0 && n < 3)
			time += 3;
		else if (n > 2 && n < 6)
			time += 4;
		else if (n > 5 && n < 9)
			time += 5;
		else if (n > 8 && n < 12)
			time += 6;
		else if (n > 11 && n < 15)
			time += 7;
		else if (n > 14 && n < 19)
			time += 8;
		else if (n > 18 && n < 22)
			time += 9;
		else if (n > 21 && n < 26)
			time += 10;
		i++;
	}
	printf("%d", time);
	return 0;
}
