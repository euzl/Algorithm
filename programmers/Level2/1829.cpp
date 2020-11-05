#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
int number_of_area;
int max_size_of_one_area;
int check[100][100]; // visit check
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void init_check(int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            check[i][j] = 0;
        }
    }
}
void bfs(int m, int n, vector<vector<int>> picture, int x, int y) {
    queue<pair<int, int>> q; // 들려야 할 인접 공간
    queue<pair<int, int>> next;
    q.push({x, y}); // 시작지점
    int color = picture[x][y];
    int area = 0; // 새로시작
    number_of_area++;
    pair<int, int> cur; // 현재지점
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        
        int x = cur.first;
        int y = cur.second;
        check[x][y]++; // visit
        area++;
        // printf("%d: (%d, %d) %d\n", color, x, y, area);
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            if ((nx >= m) || (nx < 0)) continue;
            int ny = y + dy[i];
            if ((ny >= n) || (ny < 0)) continue;
            if (check[nx][ny]) continue;
            
            if (picture[nx][ny] == color) {
                q.push({nx, ny});
                check[nx][ny]++; // 넣었다고 체크
            } else {
                next.push({nx, ny});
            }
        }
    }
    
    while(!next.empty()) {
        cur = next.front();
        next.pop();
        int x = cur.first;
        int y = cur.second;
        if (check[x][y]) continue;
        
        bfs(m, n, picture, x, y);
    }
    
    if (color == 0) {
        number_of_area--;
    } else if (area > max_size_of_one_area) max_size_of_one_area = area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    
    init_check(m,n);
    bfs(m, n, picture, 0, 0);
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
