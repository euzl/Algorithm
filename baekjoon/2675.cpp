//2675::문자열반복
#include <iostream>
using namespace std;

int main() {
	int t, r;
	char s[20];
	string p;
	cin >> t;
	while (t--) {
		cin >> r;
		p = "";
		cin >> s;
		for (int i = 0; i < 20; i++) {
			if (s[i] == '\0')
				break;
			for (int j = 0; j < r; j++) {
				p += s[i];
			}
		}
		cout << p << endl;
	}
	return 0;
}
