// 10872::팩토리얼
#include <iostream>
using namespace std;

int factorial(int _n, int &_mul) {
	if (_n != 0) {
		_mul *= _n;
		factorial(_n - 1, _mul);
	}
	else {
		return _mul;
	}
}

int main() {
	int n, mul = 1;
	cin >> n;
	cout << factorial(n, mul);

	return 0;
}
