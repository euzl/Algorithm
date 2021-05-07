#include <string>
#include <vector>

using namespace std;
int M,N;
bool findBlank(vector<vector<int>> lock) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (lock[i][j] == 0) return false;
        }
    }
    return true;
}
void rotate(vector<vector<int>> &key) {
    vector<vector<int>> source;
    source.assign(key.begin(), key.end());

    for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++) {
            key[j][M-(i+1)] = source[i][j];
        }
    }
}
pair<int, int> findFirst(vector<vector<int>> v, int type) {
    int size = type==1 ? M : N;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (v[i][j] == type) return {i, j};
        }
    }
    return {0, 0}; // 없는데.. 어쩌지..
}
bool unlock(vector<vector<int>> key, vector<vector<int>> lock, pair<int, int> l, pair<int, int> k) {
    int ni, nj;
    for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++) {
            ni = i + l.first-k.first, nj = j + l.second-k.second;
            if (key[i][j] == 0) continue;
            if (ni<0||ni>=N||nj<0||nj>=N) continue;
            if (lock[ni][nj] == 1) return false;
            lock[ni][nj] = 1;
        }
    }
    return findBlank(lock);
}
bool connect(vector<vector<int>> key, vector<vector<int>> lock) {
    pair<int, int> l = findFirst(lock, 0); //first hom
    for (int r=0; r<M; r++) {
        for (int c=0; c<M; c++) {
            if (key[r][c] == 0) continue;
            if (unlock(key, lock, l, {r,c})) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    if (findBlank(lock)) return true;

    for (int i=0; i<4; i++) {
        if (connect(key, lock)) return true;
        rotate(key);
    }
    return false;
}
