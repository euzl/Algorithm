// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int max = 0; // 최대 binary gap 저장
    int ptr = 0; // 현재 가리키는 2진수
    int subSize = 0; // 부분 binary gap 크기
    bool isExist = false; // binary gap 존재 여부

    while (N > 0) {
        ptr = N%2;
        N /= 2;
        if (ptr == 1) {
            isExist = true;
            max = max > subSize ? max : subSize; // get max
            subSize = 0; // init
            continue;
        }
        if (isExist) {
            subSize++;
        }
    }

    return max;
}
