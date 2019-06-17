// 11720 :: 숫자의 합
#include <iostream>
using namespace std;
int main() {
	int size;
	cin >> size;
	int number;
	cin >> number;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += number % 10;
		number /= 10;
	}
	cout << sum << endl;
	return 0;
}
