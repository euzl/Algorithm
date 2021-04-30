#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt[502];
pair<float, int> p[502];

bool compare(pair<float, int> a, pair<float,int> b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int size = stages.size();
    for (int s : stages) {
        ++cnt[s];
    }
    
    // 실패율 구하기
    for (int i=1; i<=N; i++) {
        if (cnt[i]) {
            p[i] = {(float(cnt[i]))/size, i};
        } else {
            p[i] = {0, i};
        }
        size -= cnt[i];
    }
    
    sort(p+1, p+N+1, compare);
    for (int i=1; i<=N; i++) {
        answer.push_back(p[i].second);
    }
    return answer;
}
