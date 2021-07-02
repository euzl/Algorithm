#include <iostream>
#include <cmath>

using namespace std;

int getSide(int s, int a, int b) {
    if (a <= s && b <= s) return -1;
    else if (a > s && b > s) return 1;
    else return 0;
}

int solution(int n, int a, int b)
{
    int total = log2(n);
    int dr; // deverse round
    int half = n/2, side, size=n/2;
    for (dr = 0; dr < total; dr++) {
        side = getSide(half, a, b);
        if (!side) break;
        size /= 2;
        half = half + side*(size);
    }
    int answer = total - dr;
    return answer;
}
