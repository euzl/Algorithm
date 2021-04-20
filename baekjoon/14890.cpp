#include <cstdio>
using namespace std;
int N=0, L=0;
#define MAX_SIZE 150
int map[MAX_SIZE][MAX_SIZE];
int ans=0;

void horizontal() {
    int cnt;
    for (int i=0; i<N; i++) {
        bool isLoad = true;
        cnt=1;
        for (int j=1; j<N; j++) {
            if (!isLoad) break;
            if (map[i][j] == map[i][j-1]) {
                ++cnt;
            } else if (map[i][j] == map[i][j-1] + 1) {
                if (cnt >= L) {
                    cnt = 1;
                    continue;
                } else {
                    isLoad = false;
                    break;
                }
            } else if (map[i][j-1] == map[i][j] + 1) {
                cnt = 1;
                if (cnt==L) {
                    cnt = 0;
                    continue;
                }
                while(1) {
                    if (map[i][j] == map[i][j+1]) {
                        ++cnt;
                        if (cnt==L) {
                            ++j;
                            break;
                        }
                    } else {
                        isLoad = false;
                        break;
                    }
                    ++j;
                    if (j == N-1) {
                        isLoad = false;
                        break;
                    }
                }
                cnt = 0;
            } else {
                isLoad = false;
                break;
            }
        }
        if (isLoad) {
            ++ans;
        }
    }
}

void vertical() {
    int cnt;
    for (int j=0; j<N; j++) {
        bool isLoad = true;
        cnt=1;
        for (int i=1; i<N; i++) {
            if (!isLoad) break;
            if (map[i][j] == map[i-1][j]) {
                ++cnt;
            } else if (map[i][j] == map[i-1][j] + 1) {
                if (cnt >= L) {
                    cnt = 1;
                    continue;
                } else {
                    isLoad = false;
                    break;
                }
            } else if (map[i-1][j] == map[i][j] + 1) {
                cnt = 1;
                if (cnt==L) {
                    cnt = 0;
                    continue;
                }
                while(1) {
                    if (map[i][j] == map[i+1][j]) {
                        ++cnt;
                        if (cnt==L) {
                            ++i;
                            break;
                        }
                    } else {
                        isLoad = false;
                        break;
                    }
                    ++i;
                    if (i == N-1) {
                        isLoad = false;
                        break;
                    }
                }
                cnt = 0;
            } else {
                isLoad = false;
                break;
            }
        }
        if (isLoad) {
            ++ans;
        }
    }
}

int main() {
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    horizontal();
    vertical();
    printf("%d", ans);
    return 0;
}
