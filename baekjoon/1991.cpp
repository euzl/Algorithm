#include <iostream>
using namespace std;
int tree[27][3];

void leftVisit(char start) {
    if (start == '.') return;
    printf("%c", start);
    leftVisit(tree[start-'A'][1]);
    leftVisit(tree[start-'A'][2]);
}

void middleVisit(char start) {
    if (start == '.') return;
    middleVisit(tree[start-'A'][1]);
    printf("%c", start);
    middleVisit(tree[start-'A'][2]);
}

void rightVisit(char start) {
    if (start == '.') return;
    rightVisit(tree[start-'A'][1]);
    rightVisit(tree[start-'A'][2]);
    printf("%c", start);
}

int main() {
    int N;
    scanf("%d", &N);
    char a, b, c;
    for (int i=0; i<N; i++) {
        cin >> a >> b >> c;
        int idx = a-'A';
        tree[idx][0] = a;
        tree[idx][1] = b;
        tree[idx][2] = c;
    }

    leftVisit('A');
    printf("\n");
    middleVisit('A');
    printf("\n");
    rightVisit('A');
    return 0;
}
