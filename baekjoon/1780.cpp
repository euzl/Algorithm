#include <cstdio>
using namespace std;
#define MAX_N 2781 // 3^7
int arr[MAX_N][MAX_N];
int result[3];

bool cutPaper(int rowStart, int colStart, int size) {
    int num = arr[rowStart][colStart];
    if (size == 1) {
        ++result[num+1];
        return true;
    }
    bool isPromising = true;
    for (int i=0; i<size; i += size/3) {
        for (int j=0; j<size; j += size/3) {
            if (cutPaper(rowStart+i, colStart+j, size/3)) {
                if (arr[rowStart + i][colStart + j] != num) {
                    isPromising = false;
                }
            } else {
                isPromising = false;
            }
        }
    }
    if (isPromising) {
        result[num+1] -= 8;
        return true;
    } else {
        return false;
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
