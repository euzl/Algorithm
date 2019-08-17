// 5622::다이얼
#include <cstdio>

int main()
{
	char num;
	int time = 0;

	while (~scanf("%d", &num)) {
		switch (int(num)) {
		case 22:
		case 23:
		case 24:
		case 25:
			time += 1;
		case 21:
		case 20:
		case 19:
			time += 1;
		case 15:
		case 16:
		case 17:
		case 18:
			time += 1;
		case 12:
		case 13:
		case 14:
			time += 1;
		case 9:
		case 10:
		case 11:
			time += 1;
		case 6:
		case 7:
		case 8:
			time += 1;
		case 3:
		case 4:
		case 5:
			time += 1;
		case 0:
		case 1:
		case 2:
			time += 3;
			break;
		}
	}
	printf("%d", time);
	return 0;
}
