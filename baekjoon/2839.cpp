// 2839::설탕배달
#include <iostream>
using namespace std;
int main(int a) {
	cin >> a;
	if ((a == 4) || (a == 7)) {
		cout << "-1" << endl;
		return 0;
	}
	switch (a % 5) {
	case 0:
		cout << a / 5 << endl;
		break;
	case 1:
		cout << (a - 6) / 5 + 2 << endl;
		break;
	case 2:
		cout << (a - 12) / 5 + 4 << endl;
		break;
	case 3:
		cout << (a - 3) / 5 + 1 << endl;
		break;
	case 4:
		cout << (a - 9) / 5 + 3 << endl;
		break;
	}
	return 0;
}
