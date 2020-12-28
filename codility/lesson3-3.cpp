#include <cmath>

int getMin(int a, int b) {
    return a < b ? a : b;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int left = A[0];
    int right = 0;
    for (int i=1; i<N; i++) {
        right += A[i];
    }

    int minDiff = abs(left-right);
    for (int P=1; P<N-1; P++) {
        left += A[P];
        right -= A[P];
        minDiff = getMin(abs(left-right), minDiff);
    }
    return minDiff;
}
