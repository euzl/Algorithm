// 4344::평균은 넘겠지
#include <cstdio>
float stu[1000];
int main()
{
	int c, n, cnt;
	float avg, sum = 0;
 	scanf("%d", &c);
	while (c--) {
		sum = 0; // 초기화
		scanf("%d", &n); // 학생수
		for (int i=0; i < n;i++) {
			scanf("%f", &stu[i]);
			sum += stu[i];
		}
		avg = sum / n;
		cnt = 0; // 초기화
		for (int i = 0; i < n; i++) {
			if (stu[i] > avg)
				cnt++;
		}
		printf("%2.3f%%\n", (float)cnt*100/n);
	}
}
