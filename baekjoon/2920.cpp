// 2920::음계
#include <iostream>
using namespace std;

int main()
{
	int arr[8];
	char flag = 'a'; // a:scending, d:descending, m:mixed
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	// 초기화!
	if (arr[0] == 1)
		flag = 'a';
	else if (arr[0] == 8)
		flag = 'd';
	else {
		cout << "mixed" << endl;
		return 0;
	}

	for (int j = 0; j < 7; j++) {
		if (flag == 'a') {
			if (arr[j] + 1 == arr[j + 1])
				continue;
			else {
				flag = 'm';
				break;
			}
		}
		else if (flag == 'd') {
			if (arr[j] - 1 == arr[j + 1])
				continue;
			else {
				flag = 'm';
				break;
			}
		}
	}

	if (flag == 'a')
		cout << "ascending" << endl;
	else if (flag == 'd')
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}
