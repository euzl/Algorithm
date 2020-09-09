using namespace std;

long long gcd(long a, long b) {
    while (b != 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long W = (long)w;
    long H = (long)h;
    return W*H - (W+H-gcd(W,H));
}
