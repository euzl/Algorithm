void maxCounter(vector<int> &counter, int N, int maxC) {
    for (int i=0; i<N; i++) {
        counter[i] = maxC;
    }
}
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // int counter[100001] = {0, };
    vector<int> counter;
    for (int i=0; i<N; i++) {
        counter.push_back(0);
    }
    int maxC = 0;

    for (int X : A) {
        if (X <= N) {
            counter[X-1]++;
            maxC = maxC > counter[X-1] ? maxC : counter[X-1]; // 갱신
        } else {
            maxCounter(counter, N, maxC);
        }
    }
    return counter;
}
