#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Item{
    char n;
    string s;
    bool operator<(Item i){return this->n<i.n?true:this->n>i.n?false:this->s<i.s;}
};

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<Item> nth;
    
    // nth 에 넣어주기
    for (string s : strings) {
        nth.push_back({s[n], s});
    }
    
    // 순서정렬
    sort(nth.begin(), nth.end());
    
    // 정렬된 strings를 answer에 넣어주기
    for (Item i : nth) {
        answer.push_back(i.s);
    }
    
    return answer;
}
