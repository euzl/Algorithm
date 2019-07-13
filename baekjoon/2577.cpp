// 2577::숫자의 개수
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int numb[10] = { 0, };
	int mul = a * b * c;
	int tmp = 0;
	while (mul != 0) {
		tmp = mul % 10;
		numb[tmp]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << numb[i] << endl;
	return 0;
}
