// 11721::열 개씩 끊어 출력하기
// 최선을 다했지만 실패 ㅠㅠ 나중에 다시 시도
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string input;
	getline(cin, input);
	char* input_arr = new char[input.size() + 1];
	strcpy(input_arr, input.size() + 1, input.c_str());
	for (int i = 0; i < input.size() + 1; i++) {
		printf("%c",input_arr[i]);
		if ((i+1) % 10 == 0)
			printf("\n");
	}
	delete[] input_arr;
	return 0;
}
