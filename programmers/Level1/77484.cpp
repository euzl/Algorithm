#include <string>
#include <vector>

using namespace std;

// 맞힌개수 (맞힌건 리스트에서 뺌)
// 나머지 all 맞/틀 가정
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correctCnt = 0;
    int zeroCnt = 0;
    for (int i=0; i<6; i++) {
        if (lottos[i]==0) {
            ++zeroCnt;
            continue;
        }
        for (int j=0; j<6; j++) {
            if (lottos[i] == win_nums[j]) {
                ++correctCnt;
                break;
            }
        }
    }
    int max = (zeroCnt+correctCnt)<2 ? 6 : 7-(zeroCnt+correctCnt);
    int min = correctCnt<2 ? 6 : 7-correctCnt;
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}
