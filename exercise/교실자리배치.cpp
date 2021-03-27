#include <cstdio>
#include <vector>
#include <random>
using namespace std;

#define STUDENT_MAX 101

int zari[100][100];
int isSeat[STUDENT_MAX] = {1, }; // 자리배치 완료된 애들 표시
int N=0, M=0;
vector<int> around[STUDENT_MAX];

void initialSeat() {
    scanf("%d %d", &N, &M); // 세로 가로

    // 기존 자리배치 (학생번호)
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &zari[i][j]);
        }
    }

    // 주변 친구들 저장
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (i != N-1) {
                around[zari[i][j]].push_back(zari[i+1][j]);
                around[zari[i+1][j]].push_back(zari[i][j]);
            }
            if (j != M-1) {
                around[zari[i][j]].push_back(zari[i][j+1]);
                around[zari[i][j+1]].push_back(zari[i][j]);
            }
        }
    }
}

int getStudentId(int x, int y) {
    random_device rd; // for seed value
    mt19937 gen(rd()); // init 난수 생성 엔진
    uniform_int_distribution<int> dis(1, N*M); // 균등한 난수열 생엉을 위한 균등 분포 정의

    int student;
    int cnt = 0;
    while(1) {
        ++cnt;
        if (cnt > N*M) return -1; // 가망이 없는 수준..

        student = dis(gen);
        while (isSeat[student]) {
            student = dis(gen);
        }

        // 이전에 주변에 앉았나
        if (x != 0) {
            auto iter = find(around[student].begin(), around[student].end(), zari[x-1][y]);
            if (iter != around[student].end()) continue;
        }
        if (y != 0) {
            auto iter = find(around[student].begin(), around[student].end(), zari[x][y-1]);
            if (iter != around[student].end()) continue;
        }

        isSeat[student] = 1;
        return student;
    }
}

void arrange() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            zari[i][j] = getStudentId(i, j);
            if (zari[i][j] == -1) {
                // 가망없다. 이전 자리를 바꾸고 오자
                if (j > 0) --j;
                else --i, j=M-1;
                isSeat[zari[i][j]] = 0; // 원래 앉았던거 빼주고!
            }
        }
    }
}

int main() {
    initialSeat();
    arrange();
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            printf("%4d", zari[i][j]);
        printf("\n");
    }

    return 0;
}
