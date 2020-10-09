#include <string>
#include <vector>

using namespace std;
int cnt=0;
bool isSosu(int n) {
    for(int i=2; i <=n/2; i++) {
        if (n%i == 0) return false;
    }
    return true;
}
void dfs(int s, vector<int> numlist, int num) {
    numlist[s] = -1;
    for (int i=0; i<numlist.size(); i++) {
        if (numlist[i] < 0) continue; // 이미 추가한거는 X
        
        printf("%d ", num);
        num = num*10 + numlist[i];
        if(isSosu(num)) cnt++;
        dfs(i, numlist, num);
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<int> numlist;

    for (char n : numbers) {
        numlist.push_back(int(n));
        printf("%d", int(n));
    }
    
    for(int i=0; i<numlist.size(); i++) {
        dfs(i, numlist, 0);
    }
    return cnt;
}
