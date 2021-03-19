#include <cstdio>
using namespace std;
int qt[64][64];

bool isOne(int _x, int _y, int _size) {
    int num = qt[_x][_y];
    for (int i=_x; i<_x+_size; i++) {
        for (int j=_y; j<_y+_size; j++) {
            if (num != qt[i][j]) return false;
        }
    }
    return true;
}

void quadTree(int _x, int _y, int _size) {
    if (isOne(_x, _y, _size)) {
        printf("%d", qt[_x][_y]);
//        printf("<%d,%d>",_x, _y);
    } else {
        _size /= 2;
        printf("(");
        quadTree(_x, _y, _size);
        quadTree(_x, _y+_size, _size);
        quadTree(_x+_size, _y, _size);
        quadTree(_x+_size, _y+_size, _size);
        printf(")");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &qt[i][j]);
        }
    }

    quadTree(0, 0, N);

    return 0;
}
