vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // int counter[100001] = {0, };
    vector<int> counter;
    for (int i=0; i<N; i++) {
        counter.push_back(0);
    }
    int max = 0;
    int maxCounter = max;

    for (int X : A) {
        if (X <= N) {
            if (counter[X-1] >= maxCounter) {
                counter[X-1]++;
                max = max > counter[X-1] ? max : counter[X-1]; // 갱신
            } else {
                counter[X-1] = maxCounter;
                counter[X-1]++;
                max = max > counter[X-1] ? max : counter[X-1]; // 갱신
            }
        } else if (X == N+1) {
            maxCounter = max;
        }
    }
    for (int i = 0; i<N; i++) {
        if (counter[i] < maxCounter) {
            counter[i] = maxCounter;
        }
    }
    return counter;
}
