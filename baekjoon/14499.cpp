#include <cstdio>
using namespace std;
int N=0, M=0, K=0;
int map[20][20];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Dice {
    int x, y; // cur
    int data[6] = {0, }; // dice data
    int top, left, right, up, down, bottom; // cur data
    Dice(int x, int y) {
        this->x = x;
        this->y = y;
        top=0, left=3, right=2, up=1, down=4, bottom=5;
    }
    void rotate(int d) {
        int temp;
        if (d==1) {
            temp = right, right=top, top=left, left=bottom, bottom=temp;
        } else if (d==2) {
            temp = left, left=top, top=right, right=bottom, bottom=temp;
        } else if (d==3) {
            temp = up, up = top, top = down, down=bottom, bottom=temp;
        } else {
            temp = down, down=top, top=up, up=bottom, bottom=temp;
        }
    }
    void move(int d) {
        x += dx[d-1], y += dy[d-1];
        if (x<0||x>=N||y<0||y>=M) {
            x -= dx[d-1], y -= dy[d-1];
            return;
        }
        rotate(d);
        if (!map[x][y]) map[x][y] = data[bottom];
        else data[bottom]=map[x][y], map[x][y]=0;

        printf("%d\n", data[top]);
    }
};
int main() {
    int x=0, y=0;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    Dice dice(x, y);
    int d;
    while(K--) {
        scanf("%d", &d);
        dice.move(d);
    }
    return 0;
}
