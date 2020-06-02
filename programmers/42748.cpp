#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (int c = 0; c < commands.size(); c++) {
        temp.clear();
        for (int i = commands[c][0]-1; i < commands[c][1]; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[c][2]-1]);
    }
    return answer;
}
