// 11720 :: 숫자의 합
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
    
	while (n--) { // n이 0이 될 때까지 
        char x;
		scanf("%c", &x); // 숫자 하나씩 입력받음
		sum += x - '0';
	}
	printf("%d", sum);
	return 0;
}
