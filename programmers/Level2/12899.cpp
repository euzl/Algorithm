#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    char otf[3] = {'1', '2', '4'};
    string answer = "";
    while (n > 0) {
        answer = otf[(n-1)%3] + answer;
        n = (n-1)/3;
    }
    return answer;
}
