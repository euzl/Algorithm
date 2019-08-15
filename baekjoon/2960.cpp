// 2960 :: 에라토스테네스의 체
// 12줄에서 i<n을 i<=n으로 바꿨더니 해결! 생각해보니 n이 소수일 때는 n이 제일 마지막에 지워진다,,,
#include <cstdio>

int main()
{
	int n, k, cnt = 0;
	bool num[1001] = { false, };
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++) // (1)2부터 n까지 모든 정수를 적는다
		num[i] = true;
	for (int i = 2; i <= n; i++) { // (2) 아직 지우지 않은 수 중 가장 작은 수를 찾는다. <= i (이것을 p라고 하고, 이 수는 소수이다.)
		if (!num[i]) 
			continue;
		for (int j = 1; j <= n; j++) { // (3) p를 지우고, 아직 지우지 않은 p의 배수를 크기 순서대로 지운다.
			if (i * j > n)
				break;
			if (!num[i * j])
				continue;
			cnt++;
			if (cnt == k) { // k번째 지우는 수
				printf("%d", i * j);
				return 0;
			}
			num[i * j] = false;
		} // (4) 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
	}

	return 0;
}
