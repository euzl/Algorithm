#include <string>
#include <vector>

using namespace std;

int getMaxIdx(int idx, int k, string number) {
    char max = '/';
    int maxIdx = -1;
    for (int i=idx; i<=k; i++) {
        if (number[i] > max) {
            max = number[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    int size = number.length();
    while(1) {
        idx = getMaxIdx(idx, k, number);
        answer = answer + number[idx];
        if (idx == k) {
            for (int i=idx+1; i<size; i++) answer = answer + number[i];
            break;
        }
        ++k;
        ++idx;
        if (k == size) break;
    }
    return answer;
}
