#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int s : scoville) {
        pq.push(s);
    }
    int answer = 0;
    int a, b, mix;
    while(1) {
        a = pq.top(); pq.pop();
        if (a >= K) break;
        
        b = pq.top(); pq.pop();
        mix = a+b*2;
        pq.push(mix);
        ++answer;
        if (pq.size() == 1 && mix < K) return -1; // K이상으로 만들 수 없는 경우
    }
    return answer;
}
