//10809::알파벳찾기
#include <iostream>
#include <string.h>
using namespace std;

string s;

int findab(char search) {
	int res = s.find(search);
	if (res >= 0 && res <= 100)
		return res;
	else
		return -1;
}

int main() {
	cin >> s;
	cout << findab('a') << ' ' << findab('b') << ' ' << findab('c') << ' ' << findab('d') << ' ' << findab('e') << ' ' << findab('f') << ' '
		<< findab('g') << ' ' << findab('h') << ' ' << findab('i') << ' ' << findab('j') << ' ' << findab('k') << ' ' << findab('l') << ' '
		<< findab('m') << ' ' << findab('n') << ' ' << findab('o') << ' ' << findab('p') << ' ' << findab('q') << ' ' << findab('r') << ' '
		<< findab('s') << ' ' << findab('t') << ' ' << findab('u') << ' ' << findab('v') << ' ' << findab('w') << ' ' << findab('x')
		<< ' ' << findab('y') << ' ' << findab('z');
	return 0;
}
