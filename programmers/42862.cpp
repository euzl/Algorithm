#include <string>
#include <vector>

using namespace std;

bool findReserve(int find, vector<int> &reserve){
    for (int i=0; i<reserve.size(); i++) {
        if (reserve[i] == find){
            reserve.erase(reserve.begin() + i);
            return true;
        }
    }
    return false; // 없음
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for (int i=0; i<lost.size(); i++) {
        if(findReserve(lost[i], reserve)){
            lost.erase(lost.begin()+i);
            i--;
        }
    }
    for (int l : lost) {
        findReserve(l-1, reserve)? :
            findReserve(l+1, reserve)? : answer--; 
    }
    return answer;
}
