#include <cstdio>
using namespace std;

unsigned int N=1, M=1;

int goTravel() {
    if (N==1) return 1;
    else if (N == 2) {
        if (M >= 7) return 4;
        else return (M+1)/2;
    }

    if (M >= 7 ) {
        return M-2;
    } else if (M >= 5) {
        return 4;
    } else {
        return M;
    }
}
int main() {
    scanf("%d %d", &N, &M);

    printf("%d", goTravel());

}
