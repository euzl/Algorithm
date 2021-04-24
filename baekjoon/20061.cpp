#include <cstdio>
using namespace std;
#define LONG 6
#define SHORT 4
int N=0, score=0;
int gd[LONG][SHORT];
int bd[LONG][SHORT];

void printGreen() {
    printf("\n");
    for (int i=0; i<LONG; i++) {
        for (int j=0; j<SHORT; j++) {
            printf("%d ", gd[i][j]);
        }
        printf("\n");
    }
}
void printBlue() {
    printf("\n");
    for (int j=0; j<SHORT; j++) {
        printf("        ");
        for (int i=0; i<LONG; i++)   {
            printf("%d ", bd[i][j]);
        }
        printf("\n");
    }
}
void slide(int start, int term, int d[][SHORT]) {
    for (int r=start; r>=0+term; r--) {
        for (int c=0; c<SHORT; c++) {
            d[r][c] = d[r-term][c];
        }
    }
    for (int r=0; r<term; r++) {
        for (int c=0; c<SHORT; c++) {
            d[r][c] = 0;
        }
    }

}
void run(int t, int y, int dmn[][SHORT]) {
    int x=0, y2=y+1;
    for (int d=0; d<LONG; d++) {
        if (dmn[x][y]) break;
        if (t==2) {
            if (dmn[x][y2]) break;
        }
        ++x;
    }
    --x;

    dmn[x][y] = 1;
    if (t==2) {
        dmn[x][y+1] = 1;
    } else if (t==3) {
        dmn[x-1][y] = 1;
    }

    // full
    int idx = 0, count = 0;
    for (int i=0; i<LONG; i++) {
        if (dmn[i][0] && dmn[i][1] && dmn[i][2] && dmn[i][3]) {
            idx = i, ++count, ++score;
        }
    }

    if(count) slide(idx, count, dmn);

    // light
    if (dmn[0][0] || dmn[0][1] || dmn[0][2] || dmn[0][3]) {
        slide(LONG-1, 2, dmn);
    } else if (dmn[1][0] || dmn[1][1] || dmn[1][2] || dmn[1][3]) {
        slide(LONG-1, 1, dmn);
    }


}

int count() {
    int sum=0;
    for (int i=0; i<LONG; i++) {
        for (int j=0; j<SHORT; j++) {
            if(bd[i][j]) ++sum;
            if(gd[i][j]) ++sum;
        }
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    int t, x, y;
    for (int i=0; i<N; i++) {
        scanf("%d %d %d", &t, &x, &y);
        run(t, y, gd);
        run(t==1?1:t==2?3:2, x, bd);

//        printBlue();
//        printGreen();
//        printf("score:%d", score);
    }
    printf("%d\n%d", score, count());


    return 0;
}
