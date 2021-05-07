#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int eSize=0;

void setExp(vector<pair<long long, char> > &exp, string expression) {
    string temp="";
    for (char e : expression) {
        if (e>='0' && e<='9') {
            temp += e;
        } else {
            exp.push_back({stoi(temp), e});
            temp = "";
        }
    }
    exp.push_back({stoi(temp), '/'}); // 마지막 암시 ^^..
    eSize = exp.size();
}
long long subtract(vector<pair<long long , char> > ex, char prev);
long long add(vector<pair<long long , char> > ex, char prev);
long long multiple(vector<pair<long long , char> > ex, char prev) {
    if (ex[0].second == '/') return ex[0].first;
    int j;
    for (int i=0; i<eSize; i++) {
        if(ex[i].second == '.') {continue;}
        else if (ex[i].second == '*') {
            for (j=i+1; j<eSize; j++) if(ex[j].second != '.') break;
            ex[i].first = ex[i].first*ex[j].first;
            ex[i].second = ex[j].second;
            ex[j].second = '.';
            --i; // 부호 갱신됐으니까
        } else if (ex[i].second == '/') {break;}
    }
    long long a=0, b=0;
    if (prev != '+') a = abs(add(ex, '*'));
    if (prev != '-') b = abs(subtract(ex, '*'));
    return max(a, b);
}

long long add(vector<pair<long long , char> > ex, char prev) {
    if (ex[0].second == '/') return ex[0].first;
    int j;
    for (int i=0; i<eSize; i++) {
        if(ex[i].second == '.') {continue;}
        else if (ex[i].second == '+') {
            for (j=i+1; j<eSize; j++) if(ex[j].second != '.') break;
            ex[i].first = ex[i].first+ex[j].first;
            ex[i].second = ex[j].second;
            ex[j].second = '.';
            --i; // 부호 갱신됐으니까
        } else if (ex[i].second == '/') {break;}
    }
    long long a=0, b=0;
    if (prev != '*')a = abs(multiple(ex, '+'));
    if (prev != '-')b = abs(subtract(ex, '+'));
    return max(a, b);
}

long long subtract(vector<pair<long long , char> > ex, char prev) {
    if (ex[0].second == '/') return ex[0].first;
    int j;
    for (int i=0; i<eSize; i++) {
        if(ex[i].second == '.') {continue;}
        else if (ex[i].second == '-') {
            for (j=i+1; j<eSize; j++) if(ex[j].second != '.') break;
            ex[i].first = ex[i].first-ex[j].first;
            ex[i].second = ex[j].second;
            ex[j].second = '.';
            --i; // 부호 갱신됐으니까
        } else if (ex[i].second == '/') {break;}
    }
    long long a=0, b=0;
    if (prev != '+') a = abs(add(ex, '-'));
    if (prev != '*') b = abs(multiple(ex, '-'));
    return max(a, b);
}

long long solution(string expression) {
    vector<pair<long long, char> > exp;
    setExp(exp, expression);
    long long m=0, a=0, s=0;
    m = abs(multiple(exp, '.'));
    a = abs(add(exp, '.'));
    s = abs(subtract(exp, '.'));
    return max({m, a, s});
}

int main() {
//    string expression = "2*2*2*2*2-2*2*2";
    string expression = "177-661*999*99-133+221+334+555-166-144-551-166*166-166*166-133*88*55-11*4+55*888*454*12+11-66+444*99";
//    string expression = "2*2*2-4-4+3+3*2";
    printf("%lld", solution(expression));
}
