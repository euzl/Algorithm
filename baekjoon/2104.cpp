#include <queue>
#include <cstdio>
using namespace std;

#define INF 100000

int main() {
    int n;
    scanf("%d", &n);
    int subSum[INF+2] = {0, };

    priority_queue<pair<int, int>> queue; // (input, idx)
    int input;
    for (int i=1; i<=n; i++) {
        scanf("%d", &input);
        queue.push(make_pair(input, i));
    }

    int subMax = -1; // 최대값 저장
    while(!queue.empty()) {
        // 현재값 = 값 + 좌우값
        subSum[queue.top().second] = queue.top().first + subSum[queue.top().second-1]
                                     + subSum[queue.top().second+1];
        // 좌,우값 갱신 (!=0 일 때 <=> 값이 있을 때)
        for (int k=queue.top().second-1; k>=0; k--) {
            if (subSum[k] == 0) {
                subSum[k+1] = subSum[queue.top().second];
                break;
            }
        }
        for (int k=queue.top().second+1; k<=n; k++) {
            if (subSum[k] == 0) {
                subSum[k-1] = subSum[queue.top().second];
                break;
            }
        }

        if (subSum[queue.top().second]*queue.top().first > subMax) {
            subMax = subSum[queue.top().second]*queue.top().first;
        }

        queue.pop();
    }

    printf("%d", subMax);
    return 0;
}
