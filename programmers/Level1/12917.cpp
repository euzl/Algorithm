#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

string solution(string s) {
    string upper = ""; // 대문자 저장
    string lower = ""; // 소문자 저장
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > 95) {
            lower += s[i];
        } else {
            upper += s[i];
        }
    }
    sort(lower.begin(), lower.end(), greater<int>());
    sort(upper.begin(), upper.end(), greater<int>());
    
    return lower + upper;
}
