// 10817 :: 세 수
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int maximum, minimum;
	maximum = max(a, b);
	maximum = max(maximum, c);
	minimum = min(a, b);
	minimum = min(minimum, c);

	cout << a + b + c - maximum - minimum;

	return 0;
}
