//1546::평균
#include <iostream>
using namespace std;
int main() {
	int n, x, sum = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > max)
			max = x;
		sum += x;
	}
	float avg = float(sum * 100) / float(max * n); // float로 설정을 안했어서 소수점이 안나왔었음
	printf("%.2f", avg);
	
	return 0;
}
