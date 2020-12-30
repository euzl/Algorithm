int solution(int K, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int subLenth = 0;
    int count = 0;

    for (int i=0; i<A.size(); i++) {
        subLenth += A[i];
        if (subLenth >= K) {
            count++;
            subLenth = 0;
        }
    }
    return count;
}
