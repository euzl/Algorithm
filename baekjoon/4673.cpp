// 4673::셀프 넘버
#include <iostream>
using namespace std;

bool num[10000]; // 생성자가 있는 수 (n이면 n-1에 저장)

// 함수 d(n) : 생성자로 인해 만들어지는 수
int dn(int a) {
	int nn = a;
	while (a) {
		nn += a % 10;
		a /= 10;
	}
	return nn;
}

int main() {
	int result; // dn함수 결과 저장용
	for (int i = 1; i < 10000; i++) {
		result = dn(i);
		if (result <= 10000) {
			num[result - 1] = true; // 생성자가 있다!
		}
	}
	for (int i = 0; i < 10000; i++) { // 생성자 없는 애들 출력
		if (!num[i])
			cout << i + 1 << endl;
	}
	return 0;
}
