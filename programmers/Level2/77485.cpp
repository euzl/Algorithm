#include <string>
#include <vector>

using namespace std;

int map[101][101];

void init(int rows, int columns) {
    int num = 1;
    for (int i=1; i<=rows; i++)
        for (int j=1; j<=columns; j++)
            map[i][j] = num++;
}

void swap(int x, int y, int next, int& min) {
    map[x][y] = next;
    if (next < min) min = next;
}

int rotate(vector<int> q) { // [x1, y1, x2, y2]
    int min = 10000;
    int temp = map[q[0]][q[1]];
    
    int i;
    for (i=q[0]; i<q[2]; i++) swap(i, q[1], map[i+1][q[1]], min);    
    for (i=q[1]; i<q[3]; i++) swap(q[2], i, map[q[2]][i+1], min);
    for (i=q[2]; i>q[0]; i--) swap(i, q[3], map[i-1][q[3]], min);    
    for (i=q[3]; i>q[1]+1; i--) swap(q[0], i, map[q[0]][i-1], min);
    swap(q[0], q[1]+1, temp, min);
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for (vector<int> q : queries) {
        answer.push_back(rotate(q));
    }
    return answer;
}
