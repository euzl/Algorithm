// 1924::2007년
#include <iostream>
using namespace std;
int main() {
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 달 별로 일수 선언
	int x, y;
	cin >> x >> y; // x월 y일
	for (int i = 1; i < x; i++) {
		y += mon[i - 1];
	}
	switch (y % 7) {
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	}
	return 0;
}
