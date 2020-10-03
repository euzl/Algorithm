#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int size;
vector<int> sticker[2];

void initSticker() {
    sticker[0].clear();
    sticker[1].clear();
    
    sticker[0].push_back(0);
    sticker[1].push_back(0);

    scanf("%d", &size);

    int num;
    for(int i=0; i<2; i++) {
        for (int j=0; j<size; j++) {
            scanf("%d", &num);
            sticker[i].push_back(num);
        }
    }

    sticker[0].push_back(0);
    sticker[1].push_back(0);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        initSticker();

        for (int i = 2; i < size + 2; i++) {
            sticker[0][i] += max(sticker[1][i - 2], sticker[1][i - 1]);
            sticker[1][i] += max(sticker[0][i - 2], sticker[0][i - 1]);
        }

        printf("%d\n", max(sticker[0][size+1], sticker[1][size+1]));
    }
    return 0;
}
