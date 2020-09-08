#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int time;
    for (int i=0; i<prices.size() - 1; i++) {
        time = 0;
        for (int j=i+1; j<prices.size()-1; j++) {
            if (prices[i] <= prices[j]) {
                time++;
            } else {
                break;
            }
        }
        time++;
        answer.push_back(time);
    }
    answer.push_back(0);
    return answer;
}
