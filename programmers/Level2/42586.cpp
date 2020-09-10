#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int day;
    for (int i=0; i<progresses.size(); i++) {
        day = 0;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            day++;
        }
        q.push(day);
    } 
    
    int f = q.front();
    int cnt = 0;
    while(!q.empty()) {
        if (f >= q.front()) {
            cnt++;
            q.pop();
        } else {
            answer.push_back(cnt);
            f = q.front();
            cnt = 0;
        }
    }
    answer.push_back(cnt);
    return answer;
}
