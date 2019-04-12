/* 1085::직사각형에서 탈출 */
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int x, y, w, h, m1, m2;
	cin >> x >> y >> w >> h;
	m1 = min(x, (w - x));
	m2 = min(y, (h - y));
	cout << min(m1, m2);
	return 0;
}
