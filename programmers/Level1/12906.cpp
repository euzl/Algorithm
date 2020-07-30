#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    int i = 0;
    for (int j=1; j<arr.size(); j++) {
        if (arr[j] != answer[i]) {
            answer.push_back(arr[j]);
            i++;
        }
    }

    return answer;
}
