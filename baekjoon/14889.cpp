#include <cstdio>
#include <cmath>
using namespace std;
int N=0;
#define MAX_SIZE 20
int S[MAX_SIZE][MAX_SIZE];
int ans=987654321;
int team[MAX_SIZE];
void solution() {
    int aTeam=0, bTeam=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (team[i] && team[i] == team[j]) {
                aTeam += S[i][j];
            } else if (!team[i] && team[i] == team[j]) {
                bTeam += S[i][j];
            }
        }
    }
    int sub = abs(aTeam-bTeam);
    if (sub < ans) ans = sub;
}
void setTeam(int start, int cnt) {
    if (cnt == N/2) {
        solution();
        return;
    }
    for (int i=start; i<N/2+cnt; i++) {
        team[i] = 1; // set
        setTeam(i+1, cnt+1);
        team[i] = 0; // remove
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    setTeam(0, 0);
    printf("%d", ans);
    return 0;
}
