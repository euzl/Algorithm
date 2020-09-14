#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char a : s) {
        if (a == ' ') {
            answer += ' ';
        } else {
            answer += a > 95 ? (char)('a'+(a-'a'+n)%26) : (char)('A'+(a-'A'+n)%26);
        }
    }
    return answer;
}
