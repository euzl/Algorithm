#include <string>
#include <vector>

using namespace std;

long long includeSum(int a, int b) {
    long long answer = 0;
    for (int i = a; i <= b; i++){
        answer += i;
    }
    return answer;
}

long long solution(int a, int b) {
    if (a > b) return includeSum(b, a);
    else return includeSum(a, b);
    return 0;
}
