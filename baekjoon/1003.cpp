/* 백준 1003번 피보나치함수 */
#include <iostream>
using namespace std;

int main() {
	int z[41]; // 0개수 저장
	int o[41]; // 1개수 저장
	int i = 2;
	int j = 0;
	int k = 0;

	// 초기 0,1 값 저장
	z[0] = 1;
	z[1] = 0;
	o[0] = 0;
	o[1] = 1;

  // 2~40 저장
	for (i; i <= 40; i++) {
		z[i] = z[i - 1] + z[i - 2]; //z 개수
		o[i] = o[i - 1] + o[i - 2]; //o 개수
	}

	cin >> i; // 테스트 케이스 개수
  for (j; j < i; j++) {
		cin >> k; // 테스트 케이스
		cout << z[k] << ' ' << o[k] << endl; // 0개수 1개수
	}

	return 0;
}
