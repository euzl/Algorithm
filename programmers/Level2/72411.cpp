#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int history[26][20];

bool desc(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

int check(int size, string menu, int ordersSize) {
    int totalCnt = 0;
    for (int i=0; i<ordersSize; i++) {
        int cnt = 0;
        for (int j=0; j<size; j++) {
            if (history[menu[j]-'A'][i]) ++cnt;
            else break;
        }
        if (cnt == size) ++totalCnt;
    }
    return totalCnt;
}

void findMenu(int start, int cnt, int size, string menu, int ordersSize, vector<pair<int, string>> &tempAnswer) {
    if (cnt == size) {
        int count = check(size, menu, ordersSize);
        if (count >= 2) tempAnswer.push_back({count, menu});
        return;
    }
    for (int i=start; i<26; i++) {
        char temp = 'A'+i;
        findMenu(i+1, cnt+1, size, menu + temp, ordersSize, tempAnswer);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    int ordersSize = orders.size();
    for (int i=0; i<ordersSize; i++) {
        for (char o : orders[i]) {
             history[o-'A'][i] = 1;
        }
    }
    
    vector<string> answer;
    vector<pair<int, string>> tempAnswer; // count 저장
    int maxCnt;

    for (int c : course) { // 갯수별 계산
        findMenu(0, 0, c, "", ordersSize, tempAnswer);
        sort(tempAnswer.begin(), tempAnswer.end(), desc);
        maxCnt = tempAnswer[0].first;
        int tSize = tempAnswer.size();
        if (!tSize) continue;
        answer.push_back(tempAnswer[0].second);
        
        for (int t=1; t<tSize; t++) {
            if (tempAnswer[t].first == maxCnt) answer.push_back(tempAnswer[t].second);
            else break;
        }
        tempAnswer.clear();
        // printf("%d\n", tempAnswer.size());
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
