// 2441::별 찍기-4
#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 0; i <=a; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int k = a-i; k > 0; k--) {
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
