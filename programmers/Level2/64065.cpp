#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXTUPLE 100001
pair<int, int> n[MAXTUPLE];
void initN() {
    for (int i=1; i<MAXTUPLE; i++) n[i] = {i, 0};
}
bool desc(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    initN();
    vector<int> answer;
    string temp = "";
    int number;
    int size = s.size();

    for (int next = 2; next <size; next++) {
        if (s[next] == '{') {
        } else if (s[next] == '}') {
            if (s[next-1] == '}') break;
            number = stoi(temp);
             n[number].second += 1;
            temp = "";
            ++next;
        } else if (s[next] == ',') {
            number = stoi(temp);
             n[number].second += 1;
            temp = "";
        } else {
             temp += s[next];
        }
    }
     sort(n, n+MAXTUPLE, desc);
     for (int i=0; i<MAXTUPLE; i++) {
         if(n[i].second == 0) break;
         answer.push_back(n[i].first);
     }
    return answer;
}
