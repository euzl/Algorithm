#include <cstdio>
using namespace std;
int hope[100003];
int isVisit[100003]; // 재방문여부파악
int isTeam[100003]; // 팀이 성사되거나 방문한 것 체크 (더 볼 필요 X)
int result;
void checkTeam(int student) {
    if (isTeam[student] == 0) {
        isTeam[student] = 1;
        ++result;
        checkTeam(hope[student]);
    }
}
void teamPossible(int student) {
    if (isTeam[student]) return;
    if (isVisit[student]) {
        // 그래프 타고 가면서 isTeam에 표시해주기
        checkTeam(student);
        return;
    }
    isVisit[student] = 1; // 방문함
    teamPossible(hope[student]);

    // visit초기화
    isVisit[student] = 0;
    isTeam[student] = 1;
}
int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        result = 0;
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%d", &hope[i]);
            isVisit[i] = 0;
            isTeam[i] = 0;
        }
        for (int i=1; i<=n; i++) teamPossible(i);
        printf("%d\n", n-result);
    }
    return 0;
}
