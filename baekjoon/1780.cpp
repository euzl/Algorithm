#include <cstdio>
using namespace std;
#define MAX_N 2781 // 3^7
int arr[MAX_N][MAX_N];
int result[3];

bool isPromising(int rowStart, int colStart, int size) {
    int start = arr[rowStart][colStart];
    for (int i = rowStart; i < rowStart + size; i++) {
        for (int j = colStart; j < colStart + size; j++) {
            if (arr[i][j] != start) return false;
        }
    }
    return true;
}

void cutPaper(int rowStart, int colStart, int size) {
    if (isPromising(rowStart, colStart, size)) {
        int num = arr[rowStart][colStart];
        ++result[num+1];
        return;
    }

    size /= 3;
    if (size == 0) return;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cutPaper(rowStart+i*size, colStart+j*size, size);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    cutPaper(0, 0, N);
    printf("%d\n%d\n%d", result[0], result[1], result[2]);
    return 0;
}
