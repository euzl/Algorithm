// 1157::단어 공부
#include <iostream>
using namespace std;

int main() {
	int a[26] = { 0, };
	int max = -1, cnt = 0, iter = -1;
	string munja;
	cin >> munja;

	for (int i = 0; i < munja.size(); i++) {
		if (munja.at(i) < 95) // 대문자 (65~90)
			a[munja.at(i) - 'A']++;
		else // 소문자 (97~122)
			a[munja.at(i) - 'a']++;
	}
	for (int j = 0; j < 26; j++) {
		if (a[j] > max) {
			max = a[j];
			iter = j;
			cnt = 0;
		}
		else if (a[j] == max)
			cnt++;
	}
	if (!cnt)
		cout << char('A' + iter) << endl;
	else
		cout << '?' << endl;
	return 0;
}
