#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isMax(vector<int> priorities, queue<int> index) {
    int front = index.front();
    index.pop();
    while(!index.empty()) {
        if (priorities[front] < priorities[index.front()]) {
            return false;
        }
        index.pop();
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int front = 0; // 현재 맨 앞
    queue<int> index;
    
    for (int i=0; i<priorities.size(); i++) {
        index.push(i);
    }
    
    while (!index.empty()) {
        front = index.front();
        if (isMax(priorities, index)) {
            index.pop();
            answer++;
            if (front == location) {
                break;
            }
        } else {
            index.pop();
            index.push(front);
        }
    }
    
    return answer;
}
