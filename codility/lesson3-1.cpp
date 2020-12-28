int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    return (Y-X)%D == 0 ? (Y-X)/D : (Y-X)/D + 1;
}
