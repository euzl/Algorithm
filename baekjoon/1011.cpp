// 1011::Fly me to the Alpha Centauri 
// 계속 시간초과 ㅠ.ㅠ

/* 규칙
제곱수일 때마다 완벽한 대칭이 됨. n^2일 때 개수는 2n-1
[n^2-n, n) : 2n-1
[n, n^2+n) : 2n

그래서
n^2 < y-x <= n^2+n  : 2n
n^2-n < y-x (거리) <= n^2 : 2n-1 
라고 생각을 했고 여러 방식으로 시도했는데 계속 시간초과가 뜬다..

일단 여기서 마무리하고 다음에 좋은 방법이 생각나면 시도해보는걸로!
*/
#include <cstdio>

int main() {
	int t, x, y;
	scanf("%d", &t);
	while (t--) {
		int i = 1;
		scanf("%d%d", &x, &y);
		while (i * i < y-x) i++;
		((i * i - i) < (y-x))?printf("%d\n", 2 * i - 1):printf("%d\n", 2 * (i - 1));
	}
	return 0;
}
