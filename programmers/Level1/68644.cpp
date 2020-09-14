#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> result;
    for (int i=0; i<numbers.size()-1; i++) {
        for (int j=i+1; j<numbers.size(); j++) {
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    for (int a : answer) {
        if (result.empty() || (a != result.back())) {
            result.push_back(a);
        }
    }
    return result;
}
