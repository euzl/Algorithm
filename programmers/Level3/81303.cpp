#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;
bool db[1000010];
vector<pair<int, int>> near;
stack<int> dList;

int u(int k, int x) {
    int idx = k;
    for (int i=0; i<x; i++) {
        idx = near[idx].first;
    }
    return idx;
}

int d(int k, int x) {
    int idx = k;
    for (int i=0; i<x; i++) {
        idx = near[idx].second;
    }
    return idx;
}

int c(int k, int n) {
    db[k] = true;
    dList.push(k);
    if (near[k].second == n) {
        near[near[k].first].second = n;
        return near[k].first;
    } else {
        near[near[k].second].first = near[k].first;
        if (near[k].first != -1) {
            near[near[k].first].second = near[k].second;
        }
        return near[k].second;
    }
}

void z(int n) {
    int re = dList.top();
    dList.pop();
    db[re] = false; // revive

    for (int i=re+1; i<n; i++) {
        if (!db[i]) {
            near[re].first = near[i].first;
            if (near[i].first != -1) {
                near[near[i].first].second = re;
            }
            near[i].first = re;
            near[re].second = i;
            return;
        }
    }
    // re is last
    for (int i=re-1; i>=0; i--) {
        if (!db[i]) {
            near[re].first = i;
            near[i].second = re;
            near[re].second = n;
            return;
        }
    }
}

string solution(int n, int k, vector<string> cmd) {
    for (int i=0; i<n; i++) {
        near.push_back({i-1, i+1});
    }

    string answer = "";
    for (string command : cmd) {
//        printf("%d\t", k);
        string b;
        stringstream ss(command);
        ss >> b;
        ss >> b;
        if (command[0] == 'U') k=u(k,stoi(b));
        else if (command[0] == 'D') k=d(k,stoi(b));
        else if (command[0] == 'C') k=c(k, n);
        else if (command[0] == 'Z') z(n);
    }
    for (int i=0; i<n; i++) {
        if (db[i]) answer += 'X';
        else answer += 'O';
    }
    return answer;
}

int main() {
    solution(24, 16, {"C", "C", "C", "C", "U 13", "Z", "Z", "D 3"});
}
