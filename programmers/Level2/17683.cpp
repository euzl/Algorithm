#include <string>
#include <vector>
#include <cstdio>
using namespace std;

string removeSharp(string s) {
    int size = s.size();
    string result = "";
    int i;
    char t;
    for (i=size-1; i>=0; i--) {
        if (s[i] == '#' && i != 0) {
            t = s[i-1]+32;
            result = t + result;
            --i;
        } else {
            result = s[i] + result;
        }
    }

    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int answerTime = -1;

    m = removeSharp(m);

    for (string mi : musicinfos) {
        int shh, smm, ehh, emm, time;
        char title[100], c[3000];
        sscanf(mi.c_str(), "%d:%d,%d:%d,%[^,],%[^,]", &shh, &smm, &ehh, &emm, title, c);
        time = (ehh*60+emm) - (shh*60+smm);

        string code(c);
        code = removeSharp(code);

        int mSize = m.size();
        int codeSize = code.size();

        int run = 0;
        int cnt = 0;
        while (run < time) {
            if (m[cnt] == code[run%codeSize]) {
                ++cnt;
                if (cnt == mSize) {
                    if (time > answerTime) {
                        answer = title;
                        answerTime = time;
                    }
                    break;
                }
            } else {
                run -= cnt;
                cnt = 0;
            }
            ++run;
        }
    }
    return answer;
}

int main() {
    string a = solution("CC#B", {"12:00,12:7,HELLO,C#C#C#C#CC#B", "13:00,13:05,WORLD,CC#B#"});

    printf("%s", a.c_str());
}
