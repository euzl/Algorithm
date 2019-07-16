// 8958::OX 퀴즈

#include <cstdio>
#include <string.h>
int main()
{
	int size, score, sum, k;
	char hh[80];
 	scanf("%d", &size);
	while (size--) {
		score = 0, sum = 0; // 초기화
		scanf("%s", &hh); // oxoxoxx 입력받음
		for (int i=0; i < strlen(hh);i++) { // 입력받은 길이의 크기만큼
			hh[i] == 'O' ? score++ : score = 0; // O이면 점수+1 X이면 점수=0으로 초기화
			sum += score;
		}
		printf("%d\n", sum);
	}
}
