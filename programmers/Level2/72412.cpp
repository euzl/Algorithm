#include <string>
#include <string.h>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
struct Applicant {
    char c, e, f;
    int score;
};

int search(vector<Applicant> lan, char c, char e, char f, int score) {
    int cnt = 0;
    for (auto a : lan) {
        if (a.score < score) continue;
        if (c != '-' && a.c != c) continue;
        if (e != '-' && a.e != e) continue;
        if (f != '-' && a.f != f) continue;
        ++cnt;
    }
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Applicant> java;
    vector<Applicant> python;
    vector<Applicant> cpp;
    char language[8], culture[9], experience[8], soulfood[8];
    int score;
    char il[8], ic[9], ie[8], is[8];
    int score2;

    for (string i : info) {
        sscanf(i.c_str(), "%s %s %s %s %d\n", il, ic, ie, is, &score2);
        // printf("%s %s %s %s %d\n", il, ic, ie, is, score2);
        if (il[0] == 'j') java.push_back({ic[0], ie[0], is[0], score2});
        else if (il[0] == 'c') cpp.push_back({ic[0], ie[0], is[0], score2});
        else python.push_back({ic[0], ie[0], is[0], score2});
    }

    for (string q : query) {
        int cnt = 0;

        sscanf(q.c_str(), "%s and %s and %s and %s %d", language, culture, experience, soulfood, &score);
        // printf("*%s %s %s %s %d\n", language, culture, experience, soulfood, score);

        if (language[0] == '-') {
            cnt += search(java, culture[0], experience[0], soulfood[0], score);
            cnt += search(python, culture[0], experience[0], soulfood[0], score);
            cnt += search(cpp, culture[0], experience[0], soulfood[0], score);
        } else if (language[0] == 'j') {
            cnt = search(java, culture[0], experience[0], soulfood[0], score);
        } else if (language[0] == 'c') {
            cnt = search(cpp, culture[0], experience[0], soulfood[0], score);
        } else {
            cnt = search(python, culture[0], experience[0], soulfood[0], score);
        } 

        answer.push_back(cnt);
    }
    return answer;
}
