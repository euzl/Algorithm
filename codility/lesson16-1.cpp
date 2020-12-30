int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() == 0) {
        return 0;
    }

    int size = 1;
    int lastPosition = B[0];

    for (int k=1; k<A.size(); k++) {
        if (A[k] > lastPosition) {
            // 안겹칠 때
            ++size;
            lastPosition = B[k]; // 갱신
        }
    }
    return size;
}
