#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        } else if (a.first == b.first) {
            if (a.second > b.second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n = 0;
    cin >> n;

    int a, b;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> queue;

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        queue.push({a, b});
    }

    while(!queue.empty()) {
        cout<< queue.top().first << ' ' << queue.top().second << "\n";
        queue.pop();
    }

    return 0;
}
