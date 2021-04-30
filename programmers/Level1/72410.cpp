#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int size = new_id.size();
    for (int i=0; i<size; i++) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z') answer += new_id[i];
        else if (new_id[i] >= 'A' && new_id[i] <= 'Z') answer += tolower(new_id[i]);
        else if (new_id[i] >= '0' && new_id[i] <= '9') answer += new_id[i];
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') answer += new_id[i];
        // 나머지 생략 ~
    }
    // 3단계
    string answer2= "";
    char last = '#';
    for (char a : answer) {
        if (a == '.') {
            if (last == '#' || last == '.') continue; // 2개연속, 시작일 때 제거
        }
        answer2 += a;
        last = a;
    }
    // 4단계
    if (answer2.back() == '.') answer2.resize(answer2.size()-1);
    
    size = answer2.size();
    if (size == 0) {
        answer2 += 'a';
    } else if (size >= 16) {
        answer2.resize(15);
        if (answer2.back() == '.') answer2.resize(answer2.size()-1);
    }
    last = answer2.back();
    while (answer2.size() <= 2) {
        answer2 += last;
    }
    return answer2;
}
