// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void check(int arr[], int num, int& rest) {
    if (arr[num] == 1) {
        // 첫 방문
        arr[num] = 0;
        rest--;
    }
}

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int arr[100001] = {0, };
    int rest = X; // 남은 갯수

    for (int i=1; i<=X; i++) {
        arr[i] = 1;
    }

    for (int i=0; i < A.size(); i++) {
        check(arr, A[i], rest);
        if (rest == 0) return i;
    }
    return -1;
}
