// 2019 카카오 개발자 겨울 인턴십 - 크레인 인형뽑기 게임 (64061)
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    int doll = 0;
    for (int i=0; i<moves.size(); i++){
        for (int j=0; j<board[1].size(); j++){
            doll = board[j][moves[i]-1];
            if(doll == 0) continue;
            else {
                board[j][moves[i]-1] = 0;
                if(bucket.empty()){
                    bucket.push_back(doll);
                } else if (bucket.back() == doll){
                    bucket.pop_back();
                    answer += 2;
                } else {
                    bucket.push_back(doll);
                }
                break;
            }
        }

    }
    return answer;
}
