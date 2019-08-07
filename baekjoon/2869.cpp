// 2869::달팽이는 올라가고 싶다.
/*
day = (v-b)/(a-b); //잠자기 전에 도착한 경우. (초과할 수도 있다고 생각함. 낮에는 0~a 만큼 이동되니까?)
day = v/(a-b); // 자고 일어나니 도착 (잠자는 동안 미끄러져서)

비쥬얼 스튜디오가 제대로 작동하면 그때 다시 시도!
*/
#include <cstdio>

int main() {
	int a, b, day = 0, v;
	scanf("%d%d%d", &a, &b, &v);
	while (day < ((v - b) / (a - b))day++;
	printf("%d", day);
	return 0;
}
