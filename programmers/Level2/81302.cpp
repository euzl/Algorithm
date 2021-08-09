#include <string>
#include <vector>
using namespace std;
int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 응시자 기준.
bool seat(vector<string> places, int r, int c) {
    int nr, nc, nnr, nnc;

    for (int i=0; i<4; i++) { // 거리 1
        nr=r+dr[i], nc=c+dc[i];
        if (nr<0||nr>=N||nc<0||nc>=N) continue;
        if (places[nr][nc] == 'X') continue;
        else if (places[nr][nc] == 'P') return false;

        // empty table
        for (int j=0; j<4; j++) { // 거리 2
            nnr=nr+dr[j], nnc=nc+dc[j];
            if (nnr<0||nnr>=N||nnc<0||nnc>=N) continue;
            if (nnr==r && nnc==c) continue;
            else if (places[nnr][nnc] == 'P') return false;
        }
    }
    return true;
}

int find(vector<string> places) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (places[i][j] == 'P') {
                if(!seat(places, i, j)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    N = places.size();
    vector<int> answer;
    for (vector<string> p : places) {
        answer.push_back(find(p));
    }
    return answer;
}
int main() {
    solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}});
}
