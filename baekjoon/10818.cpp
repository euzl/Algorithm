// 10818:: 최소, 최대

#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = arr[0];
	int mini = arr[0];
	for (int j = 1; j < n; j++) {
		if (max < arr[j]) {
			max = arr[j];
		}
		if (mini > arr[j])
			mini = arr[j];
	}
	cout << mini << ' ' << max;

	delete arr;

	return 0;
}
