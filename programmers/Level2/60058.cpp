#include <string>
#include <vector>

using namespace std;

string step2(string p) {
    if (p == "") return p;
    string u="", v="";
    int cnt = 0;
    bool isU = true;
    for (char a : p) {
        if (isU) {
            u += a;
            if (a=='(') ++cnt;
            else --cnt;
            if (cnt == 0) isU = false;
        } else {
            v += a;
        }
    }
    // printf("u=%s v=%s\n", u.c_str(), v.c_str());
    v = step2(v);

    if (u[0] == '(') {
        return u + step2(v);
    } else {
        string w = '(' + step2(v) + ')';
        int uSize = u.size();
        for (int i=1; i<uSize-1; i++) {
            if (u[i] == '(') w += ')';
            else w += '(';
        }
        return w;
    }
}

string solution(string p) {
    string answer = step2(p);
    return answer;
}
