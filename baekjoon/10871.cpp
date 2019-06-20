// 10871 :: x 보다 작은 
#include <iostream>
using namespace std;
int main() {
	int n, x, a, cnt = 0;
	cin >> n >> x;
	int* arr = new int[n];
	while (n--) {
		cin >> a;
		if (a < x)
		{
			arr[cnt] = a;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << arr[i] << ' ';
	}

	delete arr;
	return 0;
}
