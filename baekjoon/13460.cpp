#include <cstdio>
#include <iostream>
using namespace std;

#define BOX_SIZE_MAX 11
char box[BOX_SIZE_MAX][BOX_SIZE_MAX];
int moveMin = -1;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};

/**
 * 공을 한 칸씩 움직이는 함수
 * @param i
 * @param my
 * @param other
 * @param isMove
 * @param isWall
 * @return 구멍에 빠진 여부.
 */
bool move(int i, pair<int, int> &my, pair<int, int> other, bool &isMove, bool &isWall) {
    my.first += dx[i];
    my.second += dy[i];
    if (box[my.first][my.second] == 'O') { // hall
        isWall = true;
        isMove = true;
        return true;
    } else if (box[my.first][my.second] == '#') { // wall
        // 좌표 원상복
        my.first -=dx[i];
        my.second -=dy[i];

        isWall = true;
    } else if (my == other) {
        // 좌표 원상복
        my.first -=dx[i];
        my.second -=dy[i];
    } else {
        isMove = true;
    }
    return false;
}

/**
 * 중력 끝까지 가면 어디로 가는지
 * @param i
 * @param red
 * @param blue
 * @param redGoingHall
 * @param blueGoingHall
 * @return 움직인 여부
 */
bool gravity(int i, pair<int, int> &red, pair<int ,int> &blue, bool &redGoingHall, bool &blueGoingHall) {
    bool isRedWall = false;
    bool isBlueWall = false;
    bool isMove = false;
    bool isMoveRecord = false;
    while(!isRedWall || !isBlueWall) { // 한 방향으로 중력 이동!
        if (!isRedWall && redGoingHall==0) {
            redGoingHall = move(i, red, blue, isMove, isRedWall);
        }

        if (!isBlueWall && !blueGoingHall) {
            blueGoingHall = move(i, blue, red, isMove, isBlueWall);
            if (blueGoingHall) break; // 파란공이 구멍에 빠지면 더 볼 필요가 없다.
        }

        if (!isMove) break;

        if (redGoingHall || isRedWall || isBlueWall) {
            isMoveRecord = isMove;
            isMove = false;
        }
    }
    return isMoveRecord;
}

void DFS(pair<int, int> red, pair<int, int> blue, int count) {
    if (count >= 10) return; // 10번 초
    if (moveMin != -1) {
        if (moveMin < count) return; // not promising
    }

    for (int i=0; i<4; i++) {
        pair<int, int> nextRed = red;
        pair<int, int> nextBlue = blue;

        bool redGoingHall = false;
        bool blueGoingHall = false;

        if (gravity(i, nextRed, nextBlue, redGoingHall, blueGoingHall)) {
            if (blueGoingHall) continue; // fail
            if (redGoingHall) {
                if (moveMin == -1) {
                    moveMin = count+1;
                } else if (moveMin > count+1) {
                    moveMin = count+1;
                }
                continue;
            }
            DFS(nextRed, nextBlue, count+1);
        }
    }
}

int main() {

    unsigned int N=1, M=1;
    pair<int ,int> redBall;
    pair<int ,int> blueBall;

    scanf("%d %d", &N, &M);

    for (int i=0;i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%c", &box[i][j]);
            if (box[i][j] == '\n') {
                scanf("%c", &box[i][j]);
            }
            if (box[i][j] == '#' || box[i][j] == '.' || box[i][j] == 'O') continue;
            if (box[i][j] == 'R') redBall = make_pair(i, j);
            else if (box[i][j] == 'B') blueBall = make_pair(i, j);
            box[i][j] = '.';
        }
    }

    DFS(redBall, blueBall, 0);
    printf("%d", moveMin);

    return 0;
}
