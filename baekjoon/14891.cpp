#include <cstdio>
#include <cmath>
using namespace std;

struct Bolt{
    int b[8] = {0, };
    int top; // 12o'clock
    Bolt *prev;
    Bolt *next;

    Bolt() {
        top = 0;
        prev = nullptr, next = nullptr;
    }

    int getTop() { return b[top]; }
    void setPrev(Bolt* prev) {
        prev->next = this;
        this->prev = prev;
    }
    void setStatus() {
        for (int i=0; i<8; i++) scanf("%1d", &b[i]);
    }
    int getRight() { return b[(top+2)%8]; }
    int getLeft() { return b[(top+6)%8]; }
    void turn(int d, Bolt *near) {
        if (near == nullptr || near == next) {
            if (prev) {
                if (prev->getRight() != this->getLeft()) prev->turn(d*(-1), this);
            }
        }
        if (near == nullptr || near == prev) {
            if (next) {
                if (next->getLeft() != this->getRight()) next->turn(d*(-1), this);
            }
        }
        top = (top-d+8)%8; // [매우중요] 돌릴지 말지 결정한 다음 회전한다!!
    }
};

int main() {
    Bolt* bolt = new Bolt[4];
    for (int i=1; i<4; i++) bolt[i].setPrev(&bolt[i-1]);

    for (int i=0; i<4; i++) {
        bolt[i].setStatus();
    }

    int K;
    scanf("%d", &K);
    int n, d;
    while(K--) {
        scanf("%d %d", &n, &d);
        bolt[n-1].turn(d, nullptr);
    }

    int ans=0;
    for (int i=0; i<4; i++) {
        ans += bolt[i].getTop()*pow(2, i);
    }
    printf("%d", ans);
    return 0;
}
