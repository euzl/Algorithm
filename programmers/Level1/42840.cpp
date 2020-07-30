#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int c1=0,c2=0,c3 = 0;
    int s1[5] = {1, 2, 3, 4, 5};
    int s2[8] = {2,1,2,3,2,4,2,5};
    int s3[10] = {3,3,1,1,2,2,4,4,5,5};
    for (int i=0; i<answers.size();i++){
        if (s1[i%5] == answers[i]) c1++;
        if (s2[i%8] == answers[i]) c2++;
        if (s3[i%10] == answers[i]) c3++;
    }
    if (c1 > c2) {
        if (c1 > c3) {
            answer.push_back(1);
        } else if (c1 < c3) {
            answer.push_back(3);
        } else {
            answer.push_back(1);
            answer.push_back(3);
        }
    } else if (c1 < c2) {
        if (c2 > c3) {
            answer.push_back(2);
        } else if (c2 < c3) {
            answer.push_back(3);
        } else {
            answer.push_back(2);
            answer.push_back(3);
        }
    } else {
        if (c1 > c3) {
            answer.push_back(1);
            answer.push_back(2);
        } else if (c1 < c3) {
            answer.push_back(3);
        } else {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    return answer;
}
