#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int N=0, M=0, hc=0, cc=0, minLen = 987654321;
pair<int, int> home[110];
pair<int, int> chicken[14];
pair<int, int> choice[14];

void chickenLength() {
    int sum = 0;
    for (int h=0; h<hc; h++) {
        int l = 0, subMin = 987654321;
        for (int c=0; c<M; c++) {
            l = abs(home[h].first - choice[c].first) + abs(home[h].second - choice[c].second);
            if (l < subMin) subMin = l;
        }
        sum += subMin;
    }
    if (sum < minLen) minLen = sum;
}

void setChicken(int cnt, int start) {
    if (cnt == M) {
        chickenLength();
        return;
    }

    for (int c=start; c<cc; c++) {
        choice[cnt] = chicken[c];
        setChicken(cnt+1, c+1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int input;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &input);
            if (input == 1) {
                home[hc++] = {i, j};
            }
            else if (input == 2) {
                chicken[cc++] = {i, j};
            }
        }
    }

    setChicken(0, 0);
    printf("%d", minLen);

    return 0;
}
