#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    for (char c : s) {
        if ((c >= 65) && (c <= 90)) { // 대문자
            return false;
        } else if ((c >= 97) && (c <= 122)) { // 소문자
            return false;
        }
    }
    return true;
}
